/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_tless.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwisoky <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 19:48:15 by dwisoky           #+#    #+#             */
/*   Updated: 2019/08/06 20:20:45 by dwisoky          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

int		redir_tless(t_io_redirect *redir)
{
	int	left_fd;
	int	pipefd[2];

	left_fd = 0;
	if (redir->io_number != -1)
		left_fd = redir->io_number;
	if (left_fd > 9999)
		return (redirect_error_fd(left_fd));
	if (pipe(pipefd) < -1)
		exit(-1);
	dup2(pipefd[0], left_fd);
	write(pipefd[1], redir->file_name, ft_strlen(redir->file_name));
	write(pipefd[1], "\n", 1);
	close(pipefd[1]);
	close(pipefd[0]);
	return (1);
}
