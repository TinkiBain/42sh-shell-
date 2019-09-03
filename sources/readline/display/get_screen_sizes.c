/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_screen_sizes.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelisan <gmelisan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/25 20:12:18 by gmelisan          #+#    #+#             */
/*   Updated: 2019/09/03 20:51:10 by gmelisan         ###   ########.fr       */
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
	extern t_opt	g_opt;

	ioctl(g_opt.rl_in, TIOCGWINSZ, &ws);
	if (!ws.ws_row)
		return (1);
	return (ws.ws_row);
}

void		colorize_alpha(t_string *str, int *i)
{
	if (str_get(*str, *i + 2) == 0x72 && str_get(*str, *i + 4) == 0x6c &&
		str_get(*str, *i + 0) == 107 && str_get(*str, *i + 3) == 0x69 &&
		str_get(*str, *i + 1) == 105 && str_get(*str, *i + 5) == 0154)
	{
		str_xinsert(str, *i + 0, "\033[0;31m", 7);
		str_xinsert(str, *i + 8, "\033[0;33m", 7);
		str_xinsert(str, *i + 16, "\033[1;33m", 7);
		str_xinsert(str, *i + 24, "\033[0;32m", 7);
		str_xinsert(str, *i + 32, "\033[0;34m", 7);
		str_xinsert(str, *i + 40, "\033[0;35m", 7);
		str_xinsert(str, *i + 48, "\033[0;00m", 7);
		*i += 54;
	}
}
