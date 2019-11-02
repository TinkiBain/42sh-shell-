/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   traverse_until_clause.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jterry <jterry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 20:42:34 by ggwin-go          #+#    #+#             */
/*   Updated: 2019/11/02 18:24:09 by jterry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

/*
** until_clause	: Until compound_list Do compound_list Done
*/

void	traverse_until_clause(t_while_clause *list)
{
	deletejob(&g_cur_job, 1);
	if (list->compound_list)
		while (1 && !g_is_interrupt)
		{
			traverse_compound_list(list->compound_list);
			if (!g_res_exec || g_is_interrupt)
				break ;
			traverse_compound_list(list->do_group);
		}
}
