/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loginfo_line.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelisan <gmelisan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 20:11:36 by gmelisan          #+#    #+#             */
/*   Updated: 2019/10/11 20:11:52 by gmelisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "loginfo.h"

void		loginfo_line(t_line *line)
{
	char c;

	if (!DEBUG || g_logfd < 0)
		return ;
	c = line->keybuf.s[0];
	ft_fdprintf(g_logfd, "-> (%c) ", ft_isprint(c) ? c : ' ');
	if (!line->vi_mode)
		ft_fdprintf(g_logfd, "EMA ");
	else if (line->vi_mode == VI_INSERT)
		ft_fdprintf(g_logfd, "VII ");
	else if (line->vi_mode == VI_COMMAND)
		ft_fdprintf(g_logfd, "VIC ");
	else if (!line->vi_mode && !line->emacs_mode)
		ft_fdprintf(g_logfd, "RAW ");
	ft_fdprintf(g_logfd,
		"[%d %d %d %d %d %d], str: \"%s\"(%d), pos: %d, kill_buf: %s",
				str_get(line->keybuf, 0), str_get(line->keybuf, 1),
				str_get(line->keybuf, 2), str_get(line->keybuf, 3),
				str_get(line->keybuf, 4), str_get(line->keybuf, 5),
				line->str->s, line->str->len, line->cpos, line->kill_buffer.s);
	ft_fdprintf(g_logfd, "\n");
}
