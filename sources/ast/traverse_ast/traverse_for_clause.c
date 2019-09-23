/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   traverse_for_clause.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggwin-go <ggwin-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 19:11:03 by ggwin-go          #+#    #+#             */
/*   Updated: 2019/09/23 20:28:36 by ggwin-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

void		traverse_for_clause(t_for_clause *list, char **env, t_pjobs *local)
{
	traverse_compound_list(list->, env, local);
	if (!g_res_exec)
	{
		traverse_compound_list(list->if_body, env, local);
	}
	else if (list->else_part)
		traverse_else_part(list->else_part, env, local);
}
