/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   traverse_compound_command.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggwin-go <ggwin-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 19:24:51 by ggwin-go          #+#    #+#             */
/*   Updated: 2019/09/14 16:51:24 by ggwin-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

void		traverse_compound_command(t_compound_cmd *cmd, char **env, int in_fork, t_pjobs *local)
{
	if (cmd->if_clause)
		traverse_if_clause(cmd->if_clause, env, local);
	// else if (cmd->for_clause)
	// 	traverse_for_clause(cmd->for_clause);
	// else if (cmd->while_clause)
	// 	traverse_while_clause()
	else
		traverse_compound_list(cmd->compound_list, env, local);
		// cmd->if_clause
	(void)in_fork;
}
