/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_redir_right.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwisoky <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/05 20:24:55 by dwisoky           #+#    #+#             */
/*   Updated: 2019/06/05 21:12:54 by dwisoky          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

int		exec_redir_right(t_attr *cmd)
{
	int	fd;

	while (cmd)
	{
		if (cmd->spec & R)
		{
			if ((fd = open(cmd->right, O_WRONLY | O_CREAT | O_TRUNC)) < 0)
				return (exec_print_error(cmd->right));
		}
		else if (cmd->spec & RR)
		{
			if ((fd = open(cmd->right, O_WRONLY | O_CREAT | O_APPEND)) < 0)
				return (exec_print_error(cmd->right));
		}
		dup2(fd, cmd->left);
		close(fd);
		cmd = cmd->next;
	}
	return (0);
}
