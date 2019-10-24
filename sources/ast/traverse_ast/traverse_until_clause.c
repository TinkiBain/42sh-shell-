/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   traverse_until_clause.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jterry <jterry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 20:42:34 by ggwin-go          #+#    #+#             */
/*   Updated: 2019/10/24 20:34:07 by jterry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

/*
** until_clause	: Until compound_list Do compound_list Done
*/

void	traverse_until_clause(t_while_clause *list, t_pjobs **local)
{
	if (list->compound_list)
		while (1)
		{
			traverse_compound_list(list->do_group, local);
			traverse_compound_list(list->compound_list, local);
			if (g_res_exec)
				break ;
		}
}
