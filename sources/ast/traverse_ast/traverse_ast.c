/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   traverse_ast.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggwin-go <ggwin-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/04 19:23:21 by ggwin-go          #+#    #+#             */
/*   Updated: 2019/09/07 16:38:25 by ggwin-go         ###   ########.fr       */
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

static void		traverse_and_or(t_and_or *elem)
{
	static int	flag;

	if (elem->next)
		traverse_and_or(elem->next);
	if (!flag || (flag == AND_IF && g_res_exec)
				|| (flag == OR_IF && !g_res_exec))
		traverse_pipeline(elem->pipeline);
	else
		return ;
	flag = elem->and_or_if;
}

static void		traverse_list(t_pars_list *list)
{
	if (list->next)
		traverse_list(list->next);
	traverse_and_or(list->and_or);
}

void			traverse_ast(t_complete_cmd *root)
{
	if (!root)
		return ;
	root->list->sep = root->sep;
	traverse_list(root->list);
	// printf("%d\n", root->sep);
}
