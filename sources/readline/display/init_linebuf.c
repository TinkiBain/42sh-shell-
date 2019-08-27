/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_linebuf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelisan <gmelisan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/02 17:19:21 by gmelisan          #+#    #+#             */
/*   Updated: 2019/08/27 19:22:00 by gmelisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "display.h"
#include "colors.h"

t_buffer		g_buffer;

void	check_newline(void)
{
	int		row;
	int		col;

	term_getpos(&row, &col);
	if (col != 0)
		ft_printf("%s%%%s\n\r", COLOR_REVVID, COLOR_EOC);
}

void	init_linebuf(t_line *line)
{
	int cols;

	if (g_check_nl)
		check_newline();
	g_check_nl = 0;
	cols = get_term_cols();
	g_buffer.b = str_xduplicate(line->prompt);
	g_buffer.original = str_xduplicate(g_buffer.b);
	g_buffer.prompt_full_len = line->prompt.len;
	pull_escseqs(&g_buffer.escseqs, &g_buffer.b);
	g_buffer.prompt_len = g_buffer.b.len;
	g_buffer.cpos = g_buffer.prompt_len;
	g_buffer.out_rows = g_buffer.b.len / cols + 1;
	g_buffer.out_cols = cols;
	g_buffer.out = build_bufout(g_buffer.b, cols);
}
