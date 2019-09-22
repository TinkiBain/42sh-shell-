/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   traverse_compound_command.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggwin-go <ggwin-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 19:24:51 by ggwin-go          #+#    #+#             */
/*   Updated: 2019/09/22 19:55:26 by ggwin-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

void		traverse_compound_command(t_compound_cmd *cmd, int in_fork, t_pjobs *local)
{
	if (cmd->if_clause)
		traverse_if_clause(cmd->if_clause, local);
	else if (cmd->while_clause)
		traverse_while_clause(cmd->while_clause, local);
	// else if (cmd->for_clause)
	// 	traverse_for_clause(cmd->for_clause);
	else
		traverse_compound_list(cmd->compound_list, local);
		// cmd->if_clause
	(void)in_fork;
}
