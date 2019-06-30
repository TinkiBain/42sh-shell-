/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_fd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwisoky <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/04 19:28:55 by dwisoky           #+#    #+#             */
/*   Updated: 2019/06/11 10:22:27 by dwisoky          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

void		return_fd(int fd[3])
{
	dup2(fd[0], 0);
	close(fd[0]);
	dup2(fd[1], 1);
	close(fd[1]);
	dup2(fd[2], 2);
	close(fd[2]);
	free (fd);
}

int			*set_fd(void)
{
	int		*fd;

	fd = (int*)ft_xmalloc(sizeof(int));
	fd[0] = dup(0);
	fd[1] = dup(1);
	fd[2] = dup(2);
	return (fd);
}
