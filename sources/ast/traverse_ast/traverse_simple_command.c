/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   traverse_simple_command.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggwin-go <ggwin-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/05 21:34:50 by ggwin-go          #+#    #+#             */
/*   Updated: 2019/09/22 19:47:59 by ggwin-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

extern char	**g_var;
extern char	**environ;

// #define IS_COPY_ENV		2

static void	traverse_cmd_pref(t_cmd_prefix *pref, t_vector *prefix_vars)
{
	while (pref)
	{
		if (pref->assignment_word)
			vec_addback(prefix_vars, &(pref->assignment_word));
		pref = pref->cmd_pref;
	}
}

static void	traverse_cmd_suf(t_cmd_suffix	*suff, t_vector *av)
{
	while (suff)
	{
		if (suff->word)
			vec_addback(av, &(suff->word));
		suff = suff->cmd_suf;
	}
}

static void	handle_previx_vars(const char **av, char ***env)
{
	while (*av)
		set_var(*(av++), env, 0);
}

void		traverse_simple_command(t_simple_cmd *cmd, int in_fork)
{
	t_vector	av;
	t_vector	prefix_vars;

	av = vec_create(0, sizeof(char *));
	if (cmd->cmd_name)
		vec_addback(&av, &(cmd->cmd_name));
	prefix_vars = vec_create(0, sizeof(char *));
	traverse_cmd_pref(cmd->cmd_pref, &prefix_vars);
	traverse_cmd_suf(cmd->cmd_suf, &av);
	if (in_fork && prefix_vars.len)
		handle_previx_vars((const char **)prefix_vars.v, &environ);
	else if (prefix_vars.len)
		g_prefix_vars = (char **)prefix_vars.v;
	if (av.len)
		call_exec((const char **)av.v);
	else if (prefix_vars.len)
		handle_previx_vars((const char **)prefix_vars.v, &g_var);
	ft_memdel(&av.v);
	ft_memdel((void *)&av);
	ft_memdel(&prefix_vars.v);
	ft_memdel((void *)&prefix_vars);
	g_prefix_vars = NULL;
}
