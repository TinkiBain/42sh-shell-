/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_open.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggwin-go <ggwin-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 18:55:38 by ggwin-go          #+#    #+#             */
/*   Updated: 2019/06/11 08:35:14 by dwisoky          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

int			exec_open(int fd, char *file)
{
	int		tmp_fd;

	if ((tmp_fd = open(file, O_RDWR | O_CREAT, 666)) == -1)
		return (-1);
	dup2(tmp_fd, fd);
	close(tmp_fd);
	return (0);
}
