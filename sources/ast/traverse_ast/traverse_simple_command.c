/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   traverse_simple_command.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggwin-go <ggwin-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/05 21:34:50 by ggwin-go          #+#    #+#             */
/*   Updated: 2019/09/18 21:18:43 by dwisoky          ###   ########.fr       */
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
			if (!*flag)
			{
				*env = create_copy_env(*env);
				*flag |= IS_COPY_ENV;
			}
			set_var((const char *)pref->assignment_word, env, 0);
		}
		pref = pref->cmd_pref;
	}
}

static void	traverse_cmd_suf(t_simple_cmd *cmd, char ***av)
{
	t_cmd_suffix	*suff;

	suff = cmd->cmd_suf;
	while (suff)
	{
		if (suff->word)
		{
			push_back_av(av, suff->word);
		}
		suff = suff->cmd_suf;
	}
}

static void	handle_pref(t_simple_cmd *cmd, char ***av, char ***new_env, int *flag)
{
	t_cmd_prefix	*pref;

	pref = cmd->cmd_pref;
	if (pref)
	{
		if (cmd->cmd_name)
		{
			traverse_cmd_pref(pref, new_env, flag);
			push_back_av(av, cmd->cmd_name);
		}
		else
			traverse_cmd_pref(pref, &g_var, flag);
	}
	else if (cmd->cmd_name)
		push_back_av(av, cmd->cmd_name);
}

void		traverse_simple_command(t_simple_cmd *cmd, char **env, int in_fork)
{
	char	**av;
	char	**new_env;
	int		flag;

	flag = in_fork;
	new_env = env;
	av = (char **)ft_xmalloc(sizeof(char *) * 2);
	ft_bzero(av, sizeof(char *) * 2);
	if (!cmd->cmd_name)
		flag |= 1;
	handle_pref(cmd, &av, &new_env, &flag);
	traverse_cmd_suf(cmd, &av);
	if (*av)
		call_exec((const char **)av, &new_env);
	if (flag & IS_COPY_ENV)
		ft_free_double_ptr_arr((void ***)&new_env);
	free(av);
}
