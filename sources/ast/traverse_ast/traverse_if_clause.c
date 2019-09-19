/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   traverse_if_clause.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggwin-go <ggwin-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 15:16:29 by ggwin-go          #+#    #+#             */
/*   Updated: 2019/09/19 18:32:37 by ggwin-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

static void	traverse_else_part(t_else_part *elem, char **env, t_pjobs *local)
{
	if (elem->head_compound)
		traverse_compound_list(elem->head_compound, env, local);
	if (!g_res_exec)
	{
		traverse_compound_list(elem->compound_list, env, local);
	}
	else
	{
		if (elem->next_else_part)
			traverse_else_part(elem->next_else_part, env, local);
		else
			traverse_compound_list(elem->compound_list, env, local);
	}
}

void		traverse_if_clause(t_if_clause *list, char **env, t_pjobs *local)
{
	traverse_compound_list(list->if_head, env, local);
	if (!g_res_exec)
	{
		traverse_compound_list(list->if_body, env, local);
	}
	else if (list->else_part)
		traverse_else_part(list->else_part, env, local);
}
