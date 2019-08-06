/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_less.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwisoky <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 17:32:45 by dwisoky           #+#    #+#             */
/*   Updated: 2019/08/06 18:44:53 by dwisoky          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

int			redir_less(t_io_redirect *redir)
{
	int		left_fd;
	int		right_fd;

	left_fd = 0;
	if (redir->io_number != -1)
		left_fd = redir->io_number;
	if ((right_fd = open(redir->file_name, O_RDONLY)) < 0)
	{
		ft_putstr_fd("error open\n", 2);
		return (-1);
	}
	dup2(right_fd, left_fd);
	close(right_fd);
	return (1);
}
