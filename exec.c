/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwisoky <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/04 19:17:56 by dwisoky           #+#    #+#             */
/*   Updated: 2019/06/06 17:33:58 by dwisoky          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

extern char **environ;

int		exec_check_attr(t_exec *cmd, int fd)
{
	if (cmd->left && exec_fill_fifo(cmd->left, fd) < 0)
		return (-1);
	if (cmd->right && exec_redir_right(cmd->right) < 0)
		return (-1);
//	if (cmd->right_fd)
	if (fork() == 0)
	{
		execve(*cmd->av, cmd->av, environ);
	}
	else
		wait(NULL);
	return (0);
}

void	exec(t_exec *cmd)
{
	int		return_value;
	int		fd[3];

	set_fd(fd);
	while (cmd)
	{
		return_value = exec_check_attr(cmd, fd[0]);
		if (return_value == -1)
		{
			return_fd(fd);
			set_fd(fd);
			printf("ERROR return_value\n");
		}
		cmd = cmd->next;
	}
	return_fd(fd);
}
