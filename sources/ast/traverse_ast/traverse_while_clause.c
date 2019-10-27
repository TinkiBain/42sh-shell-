/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   traverse_while_clause.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggwin-go <ggwin-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 19:15:50 by ggwin-go          #+#    #+#             */
/*   Updated: 2019/10/27 16:56:04 by ggwin-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

/*
** while_clause	: While compound_list Do compound_list Done
*/

void	traverse_while_clause(t_while_clause *list, t_pjobs **local)
{
	if (list->compound_list)
		while (1 && !g_is_interrupt)
		{
			traverse_compound_list(list->compound_list, local);
			if (g_res_exec || g_is_interrupt)
				break ;
			traverse_compound_list(list->do_group, local);
		}
}
