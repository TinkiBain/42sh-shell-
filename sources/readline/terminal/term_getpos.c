/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   term_getpos.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelisan <gmelisan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/27 17:22:21 by gmelisan          #+#    #+#             */
/*   Updated: 2019/08/27 17:22:25 by gmelisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "terminal.h"

int		term_getpos(int *row, int *col)
{
	char	buf[ONECAP_BUFFER];
	int		i;

	*row = 0;
	*col = 0;
	if (!g_cap.get_pos)
		return (1);
	bzero(buf, ONECAP_BUFFER);
	term_putstr(g_cap.get_pos);
	read(STDIN, buf, ONECAP_BUFFER - 1);
	*row = ft_atoi(buf + 2) - 1;
	i = 0;
	while (i < ONECAP_BUFFER && buf[i] != ';')
		i++;
	*col = ft_atoi(buf + ++i) - 1;
	return (0);
}
