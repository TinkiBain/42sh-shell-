/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_set.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggwin-go <ggwin-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 16:51:48 by dwisoky           #+#    #+#             */
/*   Updated: 2019/09/10 19:38:48 by ggwin-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

void			redir_set(void)
{
	extern	char *g_tty;

	g_tty = ttyname(0);
	g_open_fd = (int *)ft_xmalloc(sizeof(int) * 1);
	*g_open_fd = 0;
}
