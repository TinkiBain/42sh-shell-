/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_linebuf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelisan <gmelisan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/02 17:19:21 by gmelisan          #+#    #+#             */
/*   Updated: 2019/10/20 03:10:52 by gmelisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "display.h"
#include "colors.h"

t_buffer		g_buffer;
extern t_opt	g_opt;

void	promptsp(void)
{
	struct winsize	ws;
	extern t_cap	g_cap;
	int				i;

	if (ioctl(g_opt.rl_in, TIOCGWINSZ, &ws) == -1)
		return ;
	if (!ws.ws_col || ws.ws_col > TERM_MAX_COL)
		return ;
	ft_putstr(COLOR_REVVID_BOLD "%" COLOR_EOC);
	i = 0;
	while (++i < ws.ws_col)
		ft_putchar(' ');
	term_putstr(g_cap.car_ret);
}

void	init_linebuf(t_line *line)
{
	int				cols;

	clear_linebuf();
	if (g_opt.promptsp)
		promptsp();
	cols = get_screen_width();
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
