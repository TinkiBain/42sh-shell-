/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_less_and.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggwin-go <ggwin-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/08 14:57:05 by dwisoky           #+#    #+#             */
/*   Updated: 2019/09/10 19:38:29 by ggwin-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

static int	redir_fill_fd(t_io_redirect *redir, int *fd_close, int *right_fd)
{
	char	*str;

	str = redir->file_name;
	while (*str)
	{
		if (*str == '-' && !(*(str + 1)))
		{
			*fd_close = 1;
			break ;
		}
		else if (*str >= '0' && *str <= '9')
			++str;
		else
			return (-1);
	}
	*right_fd = ft_atoi(redir->file_name);
	if (!(*redir->file_name >= '0' && *redir->file_name <= '9'))
		*right_fd = -1;
	return (1);
}

int			redir_less_and(t_io_redirect *redir)
{
	int		fd_close;
	int		right_fd;

	right_fd = -1;
	fd_close = 0;
	if (redir->io_number == -1)
		redir->io_number = 0;
	if (redir_fill_fd(redir, &fd_close, &right_fd) < 0)
		return (-1);
	if (right_fd == -1 && fd_close)
	{
		close(redir->io_number);
		return (1);
	}
	if (dup2(right_fd, redir->io_number) < 0)
		return (redirect_error_dup(right_fd));
	if (fd_close && right_fd != -1)
		close(right_fd);
	return (1);
}
