/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   traverse_command.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jterry <jterry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 18:14:01 by ggwin-go          #+#    #+#             */
/*   Updated: 2019/10/24 21:00:39 by jterry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

void		traverse_command(t_command *cmd, int in_fork, t_pjobs **local)
{
	if (cmd->simple_command)
		traverse_simple_command(cmd->simple_command, in_fork, local);
	else if (cmd->compound_command)
	{
		if (cmd->redirect_list)
			traverse_redirect_list(cmd->redirect_list, local);
		traverse_compound_command(cmd->compound_command, local);
		redir_reset();
	}
	else if (cmd->function_definition)
		traverse_function_definition(cmd->function_definition);
}
