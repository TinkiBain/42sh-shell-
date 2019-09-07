/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   traverse_ast.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggwin-go <ggwin-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/04 19:23:21 by ggwin-go          #+#    #+#             */
/*   Updated: 2019/09/07 21:30:40 by ggwin-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

static void		traverse_pipeline(t_pipeline *elem)
{
	extern char	**environ;

	traverse_pipe_sequence(elem->pipe_sequence, environ);
	if (elem->bang)
		g_res_exec = (!g_res_exec) ? 1 : 0;
}

static void		traverse_and_or(t_and_or *elem, int flag1)
{
	static int	flag;

	flag = flag1;
	if (elem->next)
		traverse_and_or(elem->next, flag);
	if (WIFEXITED(g_res_exec))
		g_res_exec = WEXITSTATUS(g_res_exec);
	set_result();
	if (!flag || (flag == AND_IF && !g_res_exec)
				|| (flag == OR_IF && g_res_exec))
		traverse_pipeline(elem->pipeline);
	else
		return ;
	flag = elem->and_or_if;
}

static void		traverse_list(t_pars_list *list)
{
	if (list->next)
		traverse_list(list->next);
	g_res_exec = 0;
	traverse_and_or(list->and_or, 0);
}

void			traverse_ast(t_complete_cmd *root)
{
	if (!root)
		return ;
	root->list->sep = root->sep;
	traverse_list(root->list);
}
