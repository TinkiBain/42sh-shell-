/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   traverse_cmd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggwin-go <ggwin-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/05 21:34:50 by ggwin-go          #+#    #+#             */
/*   Updated: 2019/08/12 18:02:14 by jterry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

static void	traverse_cmd_pref(t_cmd_prefix *pref, char ***env,
											int *is_copy_env, int in_fork)
{
	while (pref)
	{
		if (pref->assignment_word)
		{
			if (!in_fork && !*is_copy_env)
				*env = create_copy_env(*env);
			*is_copy_env = 1;
			handle_token_assignment_word(pref->assignment_word, env);
		}
		else
			redirect(pref->io_redir);
		pref = pref->cmd_pref;
	}
}

void		traverse_cmd(t_cmd *cmd, char **env, int in_fork)
{
	t_cmd_suffix	*suff;
	t_cmd_prefix	*pref;
	char			**av;
	char			**new_env;
	int				is_copy_environ;
	char			*tmp;

	is_copy_environ = 0;
	new_env = env;
	av = (char **)ft_xmalloc(sizeof(char *) * 2);
	ft_bzero(av, sizeof(char *) * 2);
	pref = cmd->cmd_pref;
	if (pref)
	{
		traverse_cmd_pref(pref, &new_env, &is_copy_environ, in_fork);
		if (cmd->cmd_word)
		{
			if ((tmp = tilda_check(cmd->cmd_word)) != NULL)
				cmd->cmd_word = tmp;
			push_back_av(&av, cmd->cmd_word);
		}
	}
	else
		push_back_av(&av, cmd->cmd_name);
	suff = cmd->cmd_suf;
	while (suff)
	{
		if (suff->word)
		{
			if ((tmp = qoutes(suff->word)) == NULL)
			{
				suff->word = ft_dollar(suff->word);
				if ((tmp = tilda_check(suff->word)) != NULL)
					suff->word = tmp;
			}
			else
				suff->word = tmp;
			push_back_av(&av, suff->word);
		}
		else
			redirect(suff->io_redir);
		suff = suff->cmd_suf;
	}
	if (*av)
		call_exec((const char **)av, &new_env);
	if (is_copy_environ)
		ft_free_double_ptr_arr((void ***)&new_env);
	free(av);
}
