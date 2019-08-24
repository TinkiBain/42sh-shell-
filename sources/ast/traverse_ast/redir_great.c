/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_great.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggwin-go <ggwin-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 20:28:36 by dwisoky           #+#    #+#             */
/*   Updated: 2019/08/24 21:48:51 by ggwin-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"
#include "lexer.h"

int		redir_great(t_io_redirect *redir)
{
	int	fd;

	if (redir->type & DGREAT)
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
	if (redir->io_number == -1)
		redir->io_number = 1;
	if (dup2(fd, redir->io_number) < 0)
		return (redirect_error_dup(redir->io_number));
	close(fd);
	return (1);
}
