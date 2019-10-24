/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   traverse_if_clause.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jterry <jterry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 15:16:29 by ggwin-go          #+#    #+#             */
/*   Updated: 2019/10/24 20:33:38 by jterry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

/*
** if_clause	: If compound_list Then compound_list else_part Fi
**				| If compound_list Then compound_list           Fi
**
** else_part	: Elif compound_list Then compound_list else_part
**				| Else                    compound_list
*/

static void	traverse_else_part(t_else_part *elem, t_pjobs **local)
{
	if (elem->head_compound)
		traverse_compound_list(elem->head_compound, local);
	if (!g_res_exec)
		traverse_compound_list(elem->compound_list, local);
	else
	{
		if (elem->next_else_part)
			traverse_else_part(elem->next_else_part, local);
		else
			traverse_compound_list(elem->compound_list, local);
	}
}

void		traverse_if_clause(t_if_clause *list, t_pjobs **local)
{
	traverse_compound_list(list->if_head, local);
	if (!g_res_exec)
		traverse_compound_list(list->if_body, local);
	else if (list->else_part)
		traverse_else_part(list->else_part, local);
}
