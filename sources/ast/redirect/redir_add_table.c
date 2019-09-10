/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_add_table.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggwin-go <ggwin-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/12 15:51:58 by dwisoky           #+#    #+#             */
/*   Updated: 2019/09/10 19:35:32 by ggwin-go         ###   ########.fr       */
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
	tmp = (int *)ft_xmalloc(sizeof(int) * size + 1);
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
