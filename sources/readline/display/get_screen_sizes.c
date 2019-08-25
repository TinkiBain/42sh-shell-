/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_screen_sizes.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelisan <gmelisan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/25 20:12:18 by gmelisan          #+#    #+#             */
/*   Updated: 2019/08/25 20:16:46 by gmelisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "display.h"

int			get_screen_width(void)
{
	return (g_buffer.out_cols);
}

int			get_screen_height(void)
{
	struct winsize	ws;

	ioctl(STDIN, TIOCGWINSZ, &ws);
	if (!ws.ws_row)
		return (1);
	return (ws.ws_row);
}
