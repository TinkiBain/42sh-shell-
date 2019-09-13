/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   traverse_simple_command.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggwin-go <ggwin-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/05 21:34:50 by ggwin-go          #+#    #+#             */
/*   Updated: 2019/09/13 22:19:29 by ggwin-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

extern char	**g_var;

#define IS_COPY_ENV		2

static int	traverse_cmd_pref(t_cmd_prefix *pref, char ***env, int *flag)
{
	int		res;

	res = 0;
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
			set_var((const char *)pref->assignment_word, env, 0);
		}
		else if ((res = redirect(pref->io_redir)) == -1)
			break ;
		pref = pref->cmd_pref;
	}
	return (res);
}

static int	traverse_cmd_suf(t_simple_cmd *cmd, char ***av)
{
	t_cmd_suffix	*suff;
	int				res;

	res = 0;
	suff = cmd->cmd_suf;
	while (suff)
	{
		if (suff->word)
		{
			suff->word = tdq(suff->word);
			push_back_av(av, suff->word);
		}
		else if ((res = redirect(suff->io_redir)) == -1)
			break ;
		suff = suff->cmd_suf;
	}
	return (res);
}

static int	handle_pref(t_simple_cmd *cmd, char ***av, char ***new_env, int *flag)
{
	t_cmd_prefix	*pref;
	int				res;

	res = 0;
	pref = cmd->cmd_pref;
	if (pref)
	{
		if (cmd->cmd_name)
		{
			res = traverse_cmd_pref(pref, new_env, flag);
			push_back_av(av, cmd->cmd_name);
		}
		else
			res = traverse_cmd_pref(pref, &g_var, flag);
	}
	else
		push_back_av(av, cmd->cmd_name);
	return (res);
}

void		traverse_simple_command(t_simple_cmd *cmd, char **env, int in_fork)
{
	char			**av;
	char			**new_env;
	int				flag;

	flag = in_fork;
	new_env = env;
	av = (char **)ft_xmalloc(sizeof(char *) * 2);
	ft_bzero(av, sizeof(char *) * 2);
	redir_set();
	if ((handle_pref(cmd, &av, &new_env, &flag) != -1) &&
			(traverse_cmd_suf(cmd, &av) != -1) && (*av))
		call_exec((const char **)av, &new_env);
	if (flag & IS_COPY_ENV)
		ft_free_double_ptr_arr((void ***)&new_env);
	free(av);
	redir_reset();
}
