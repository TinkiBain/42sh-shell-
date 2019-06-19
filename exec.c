/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggwin-go <ggwin-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/04 19:17:56 by dwisoky           #+#    #+#             */
/*   Updated: 2019/06/11 12:39:14 by dwisoky          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

int		exec_redir(t_attr *attr, int fd)
{
	t_bits	bits;
	int		return_value;

	return_value = 0;
	while (attr)
	{
		bits = attr->spec.bits;
		if (bits.o)
			return_value = exec_open(attr->left_fd, attr->file);
		else if (bits.r || bits.rr)
			return_value = exec_redir_right(attr);
		else if (bits.l || bits.ll || bits.lll)
			return_value = exec_fill_fifo(attr, fd);
		if (return_value == -1)
			return (return_value);
		attr = attr->next;
	}
	return(1);
}

int		exec_check_attr(t_exec *cmd, int fd)
{
	extern char **environ;

	(void)cmd;
	if (cmd->attr && exec_redir(cmd->attr, fd) < 0)
		return (-1);
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
	int		*fd;

	fd = set_fd();
	while (cmd)
	{
		if (cmd->ispipe)
			
		return_value = exec_check_attr(cmd, fd[0]);
		if (return_value == -1)
		{
			return_fd(fd);
			fd = set_fd();
			printf("ERROR return_value\n");
		}
		cmd = cmd->next;
	}
	return_fd(fd);
}
