/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   traverse_ast.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggwin-go <ggwin-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/24 21:49:03 by ggwin-go          #+#    #+#             */
/*   Updated: 2019/08/27 15:52:07 by ggwin-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

static void	and_or_iter_in_order(t_and_or *root)
{
	traverse_pipeline(root->pipeline);
	if (WIFEXITED(g_res_exec))
		g_res_exec = WEXITSTATUS(g_res_exec);
	set_result();
	if (root->and_or)
	{
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
	{
		g_res_exec = 0;
		and_or_iter_in_order(root->and_or);
	}
}
