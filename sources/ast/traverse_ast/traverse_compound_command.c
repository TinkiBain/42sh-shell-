/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   traverse_compound_command.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggwin-go <ggwin-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 19:24:51 by ggwin-go          #+#    #+#             */
/*   Updated: 2019/11/02 19:40:03 by ggwin-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

void		traverse_compound_command(t_compound_cmd *cmd, t_pjobs **local)
{
	if (cmd->if_clause)
		traverse_if_clause(cmd->if_clause, local);
	else if (cmd->for_clause)
		traverse_for_clause(cmd->for_clause, local);
	else if (cmd->while_clause)
		traverse_while_clause(cmd->while_clause);
	else if (cmd->until_clause)
		traverse_until_clause(cmd->until_clause);
	else if (cmd->case_clause)
		traverse_case_clause(cmd->case_clause, local);
	else
		traverse_compound_list(cmd->compound_list);
}
