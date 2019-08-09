/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   traverse_ast.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggwin-go <ggwin-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/04 19:23:21 by ggwin-go          #+#    #+#             */
/*   Updated: 2019/08/04 18:49:47 by ggwin-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

static void	and_or_iter_in_order(t_and_or *root)
{
	g_res_exec = 0;
	traverse_pipeline(root->pipeline);
	if (root->and_or)
	{
		if (WIFEXITED(g_res_exec))
			g_res_exec = WEXITSTATUS(g_res_exec);
		else
			g_res_exec = 1;
		if ((root->and_or_if == AND_IF && !g_res_exec) ||
				(root->and_or_if == OR_IF && g_res_exec))
			and_or_iter_in_order(root->and_or);
	}
}

void		traverse_ast(t_pars_list *root)
{
	if (!root)
		return ;
	if (root->list)
	{
		traverse_ast(root->list);
	}
	if (root->and_or)
		and_or_iter_in_order(root->and_or);
}
