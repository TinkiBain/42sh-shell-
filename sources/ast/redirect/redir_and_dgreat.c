/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_and_dgreat.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwisoky <dwisoky@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/08 14:27:02 by dwisoky           #+#    #+#             */
/*   Updated: 2019/10/13 12:32:12 by dwisoky          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

int			redir_and_dgreat(t_io_redirect *redir)
{
	int		fd;

	fd = -1;
	if (redir->io_number == -1)
		redir->io_number = 1;
	if (redir->file_name)
		if (!(fd = open(redir->file_name, O_WRONLY | O_CREAT | O_APPEND,
						0644)))
			return (redirect_error_open(redir->file_name));
	if (fd >= 0)
		dup2(fd, 2);
	if (dup2(2, redir->io_number) < 0)
	{
		close(fd);
		return (redirect_error_dup(redir->io_number));
	}
	close(fd);
	return (1);
}
