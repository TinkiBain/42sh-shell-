/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_redir_right.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggwin-go <ggwin-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/05 20:24:55 by dwisoky           #+#    #+#             */
/*   Updated: 2019/06/10 20:30:10 by ggwin-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

int		exec_redir_right(t_attr *cmd)
{
	int	fd;

	if (cmd->file && (fd = 1))
	{
		if (cmd->spec.bits.r)
		{
			if ((fd = open(cmd->file, O_WRONLY | O_CREAT | O_TRUNC, 666)) < 0)
				return (exec_print_error(cmd->file));
		}
		else if (cmd->spec.bits.rr)
		{
			if ((fd = open(cmd->file, O_WRONLY | O_CREAT | O_APPEND, 666)) < 0)
				return (exec_print_error(cmd->file));
		}
		dup2(fd, cmd->right_fd);
		close(fd);
	}
	if (cmd->spec.bits.rd)
		dup2(cmd->left_fd, cmd->right_fd);
	if (cmd->spec.bits.c)
		close(cmd->right_fd);
	return (0);
}
