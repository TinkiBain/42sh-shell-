/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_set.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwisoky <dwisoky@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 16:51:48 by dwisoky           #+#    #+#             */
/*   Updated: 2019/10/15 20:39:52 by dwisoky          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

void			redir_set(void)
{
	extern	char *g_tty;

	g_tty = ttyname(0);
	if (!g_open_fd)
	{
		g_open_fd = (int *)ft_xmalloc(sizeof(int) * 1);
		*g_open_fd = 0;
	}
}
