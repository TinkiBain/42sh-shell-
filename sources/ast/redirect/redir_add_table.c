/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_add_table.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwisoky <dwisoky@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/12 15:51:58 by dwisoky           #+#    #+#             */
/*   Updated: 2019/10/13 12:32:10 by dwisoky          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

void	redir_add_fd_table(int fd)
{
	int	*tmp;
	int	size;
	int	i;

	size = 0;
	if (g_open_fd)
		size = *g_open_fd + 1;
	i = 0;
	if (size)
		tmp = (int *)ft_xmalloc(sizeof(int) * (size + 1));
	else
	{
		tmp = (int *)ft_xmalloc(sizeof(int) * (size + 2));
		tmp[0] = 0;
	}
	while (i < size)
	{
		tmp[i] = g_open_fd[i];
		++i;
	}
	tmp[i] = fd;
	tmp[0]++;
	free(g_open_fd);
	g_open_fd = tmp;
}
