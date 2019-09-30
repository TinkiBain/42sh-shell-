/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   traverse_command.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggwin-go <ggwin-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 18:14:01 by ggwin-go          #+#    #+#             */
/*   Updated: 2019/09/30 22:08:51 by ggwin-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

void		traverse_command(t_command *cmd, int in_fork, t_pjobs *local)
{
	extern t_vector	g_func_defs;

	if (cmd->simple_command)
		traverse_simple_command(cmd->simple_command, in_fork);
	else if (cmd->compound_command)
	{
		local->workgpid = 1;
		if (cmd->redirect_list)
			traverse_redirect_list(cmd->redirect_list);
		traverse_compound_command(cmd->compound_command, local);
	}
	else if (cmd->function_definition)
		traverse_function_definition(cmd->function_definition, &g_func_defs);
}
