/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cmd_name.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggwin-go <ggwin-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 17:24:39 by ggwin-go          #+#    #+#             */
/*   Updated: 2019/09/13 22:19:06 by ggwin-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

static char	*get_cmd_name_from_simple_command(t_simple_cmd *cmd)
{
	cmd->cmd_name = tdq(cmd->cmd_name);
	return (cmd->cmd_name);
}

char		*get_cmd_name(t_command *cmd)
{
	if (cmd->simple_command)
		return (get_cmd_name_from_simple_command(cmd->simple_command));
	return (NULL);
	// else if (cmd->compound_command)
	// {
	// 	if (cmd->redirect_list)
	// 		traverse_redirect_list(cmd->redirect_list);
	// 	traverse_compound_command(cmd->compound_command, env, in_fork);
	// }
	// else if (cmd->function_definition)
	// 	traverse_function_definition(cmd->function_definition, env, in_fork);
}
