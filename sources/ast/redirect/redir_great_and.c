/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_great_and.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwisoky <dwisoky@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/07 18:23:51 by dwisoky           #+#    #+#             */
/*   Updated: 2019/10/13 12:32:22 by dwisoky          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

static int	redir_great_and_close(t_io_redirect *redir)
{
	if (redir->io_number == -1)
		redir->io_number = 1;
	close(redir->io_number);
	return (1);
}

static int	fill_fd(t_io_redirect *redir, int *close, int *right_fd)
{
	char	*str;

	str = redir->file_name;
	while (*str)
		if (*str >= '0' && *str <= '9')
			++str;
		else if (*str == '-' && !(*(str + 1)))
		{
			++str;
			*close = 1;
		}
		else
			break ;
	if (!(*str))
		*right_fd = ft_atoi(redir->file_name);
	else if (redir->io_number > 2)
		return (redirect_error_ambiguous(redir->file_name));
	else if ((*right_fd = open(redir->file_name, O_WRONLY, O_CREAT, O_APPEND,
					0664)) < 0)
		return (redirect_error_open(redir->file_name));
	return (1);
}

int			redir_great_and(t_io_redirect *redir)
{
	int		right_fd;
	int		fd_close;

	fd_close = 0;
	right_fd = -1;
	if (*(redir->file_name) == '-' && !*(redir->file_name + 1))
		return (redir_great_and_close(redir));
	else if (redir->io_number == -2)
		return (redirect_error_range_fd());
	else if (fill_fd(redir, &fd_close, &right_fd) < 0)
		return (-1);
	if (redir->io_number == -1)
		redir->io_number = 1;
	if (right_fd != -1)
		if (dup2(right_fd, redir->io_number) < 0)
		{
			close(right_fd);
			return (redirect_error_dup(redir->io_number));
		}
	if (fd_close)
		close(right_fd);
	return (1);
}
