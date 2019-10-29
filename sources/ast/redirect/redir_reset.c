/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_reset.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwisoky <dwisoky@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 17:08:30 by dwisoky           #+#    #+#             */
/*   Updated: 2019/10/29 18:21:09 by dwisoky          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

extern char		g_tty_name[3][1024];

static void		close_all_fd(void)
{
	int			i;

	if (!g_open_fd)
		return ;
	i = 0;
	while (++i <= *g_open_fd)
	{
		if (g_open_fd[i] > -1)
			close(g_open_fd[i]);
	}
	free(g_open_fd);
	g_open_fd = NULL;
}

void			redir_reset(void)
{
	int			fd;
	int			i;

	close_all_fd();
	i = 0;
	while (i < 3)
	{
		fd = open(g_tty_name[i], O_RDWR | O_APPEND);
		if (fd > -1)
		{
			dup2(fd, i);
			if (fd != i)
				close(fd);
		}
		++i;
	}
}
