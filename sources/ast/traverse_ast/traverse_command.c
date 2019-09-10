/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   traverse_command.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggwin-go <ggwin-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 18:14:01 by ggwin-go          #+#    #+#             */
/*   Updated: 2019/09/10 19:27:36 by ggwin-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

void		traverse_command(t_command *cmd, char **env, int in_fork)
{
	if (cmd->simple_command)
	{
		traverse_redirect_list(cmd->redirect_list);
		traverse_simple_command(cmd->simple_command, env, in_fork);
	}
	else if (cmd->redirect_list)
		traverse_redirect_list(cmd->redirect_list);
	else if (cmd->compound_command)
		traverse_compound_command(cmd->compound_command, env, in_fork);
}
