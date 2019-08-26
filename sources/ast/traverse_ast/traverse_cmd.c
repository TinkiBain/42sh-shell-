/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   traverse_cmd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggwin-go <ggwin-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/05 21:34:50 by ggwin-go          #+#    #+#             */
/*   Updated: 2019/08/25 23:05:39 by ggwin-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

extern char	**g_var;

#define IS_COPY_ENV		2

static void	traverse_cmd_pref(t_cmd_prefix *pref, char ***env, int *flag)
{
	while (pref)
	{
		if (pref->assignment_word)
		{
			pref->assignment_word = tdq(pref->assignment_word);
			if (!*flag)
			{
				*env = create_copy_env(*env);
				*flag |= IS_COPY_ENV;
			}
			handle_token_assignment_word(pref->assignment_word, env);
		}
		else
			redirect(pref->io_redir);
		pref = pref->cmd_pref;
	}
}

static int	traverse_cmd_suf(t_cmd *cmd, char ***av)
{
	t_cmd_suffix	*suff;

	suff = cmd->cmd_suf;
	while (suff)
	{
		if (suff->word)
		{
			suff->word = tdq(suff->word);
			push_back_av(av, suff->word);
		}
		else
			redirect(suff->io_redir);
		suff = suff->cmd_suf;
	}
	return (0);
}

static int	handle_pref(t_cmd *cmd, char ***av, char ***new_env, int *flag)
{
	t_cmd_prefix	*pref;

	pref = cmd->cmd_pref;
	if (pref)
	{
		if (cmd->cmd_word)
		{
			traverse_cmd_pref(pref, new_env, flag);
			push_back_av(av, cmd->cmd_word);
		}
		else
			traverse_cmd_pref(pref, &g_var, flag);
	}
	else
		push_back_av(av, cmd->cmd_name);
	return (0);
}

void		traverse_cmd(t_cmd *cmd, char **env, int in_fork)
{
	char			**av;
	char			**new_env;
	int				flag;

	flag = in_fork;
	new_env = env;
	av = (char **)ft_xmalloc(sizeof(char *) * 2);
	ft_bzero(av, sizeof(char *) * 2);
	redir_set();
	handle_pref(cmd, &av, &new_env, &flag);
	traverse_cmd_suf(cmd, &av);
	if (*av)
		call_exec((const char **)av, &new_env);
	if (flag & IS_COPY_ENV)
		ft_free_double_ptr_arr((void ***)&new_env);
	free(av);
	redir_reset();
}
