/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_great.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwisoky <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 20:28:36 by dwisoky           #+#    #+#             */
/*   Updated: 2019/08/06 21:02:02 by dwisoky          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

int		redir_great(t_io_redirect *redir, int dgreat)
{
	int	left_fd;
	int	fd;

	if (dgreat)
	{
		if ((fd = open(redir->file_name, O_WRONLY | O_CREAT | O_APPEND,
						0644)) < 0)
		return (redirect_error_open(redir->file_name));
	}
	else
	{
		if ((fd = open(redir->file_name, O_WRONLY | O_CREAT | O_TRUNC,
						0644)) < 0)
		return (redirect_error_open(redir->file_name));
	}
	left_fd = 1;
	if (redir->io_number != -1)
		left_fd = redir->io_number;
	if (left_fd > 9999)
		return (redirect_error_fd(left_fd));
	dup2(fd, left_fd);
	close(fd);
	return (1);
}
