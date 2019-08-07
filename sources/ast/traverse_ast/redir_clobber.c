/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_clobber.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwisoky <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/07 21:55:11 by dwisoky           #+#    #+#             */
/*   Updated: 2019/08/07 21:59:59 by dwisoky          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

int		redir_clober(t_io_redirect *redir)
{
	int	left_fd;
	int	fd;

	printf("%s\n", redir->file_name);
	if ((fd = open(redir->file_name, O_WRONLY | O_CREAT | O_TRUNC,
					0644)) < 0)
		return (redirect_error_open(redir->file_name));
	left_fd = 1;
	if (redir->io_number != -1)
		left_fd = redir->io_number;
	if (left_fd > 9999)
		return (redirect_error_fd(left_fd));
	dup2(fd, left_fd);
	close(fd);
	return (1);
}
