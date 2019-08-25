/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_less.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggwin-go <ggwin-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 17:32:45 by dwisoky           #+#    #+#             */
/*   Updated: 2019/08/24 20:59:23 by ggwin-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

int			redir_less(t_io_redirect *redir)
{
	int		right_fd;

	if (redir->io_number == -1)
		redir->io_number = 0;
	if ((right_fd = open(redir->file_name, O_RDONLY)) < 0)
		return (redirect_error_open(redir->file_name));
	if (dup2(right_fd, redir->io_number) < 0)
	{
		close(right_fd);
		return (redirect_error_dup(redir->io_number));
	}
	close(right_fd);
	return (1);
}
