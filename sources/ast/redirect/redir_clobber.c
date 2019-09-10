/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_clobber.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggwin-go <ggwin-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/07 21:55:11 by dwisoky           #+#    #+#             */
/*   Updated: 2019/09/10 19:36:24 by ggwin-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

int		redir_clobber(t_io_redirect *redir)
{
	int	left_fd;
	int	fd;

	if ((fd = open(redir->file_name, O_WRONLY | O_CREAT | O_TRUNC,
					0644)) < 0)
		return (redirect_error_open(redir->file_name));
	left_fd = 1;
	if (redir->io_number != -1)
		left_fd = redir->io_number;
	if (dup2(fd, left_fd) < 0)
		return (redirect_error_dup(left_fd));
	close(fd);
	return (1);
}
