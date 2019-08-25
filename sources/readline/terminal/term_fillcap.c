/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   term_fillcap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelisan <gmelisan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/25 20:28:45 by gmelisan          #+#    #+#             */
/*   Updated: 2019/08/25 21:37:04 by gmelisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "terminal.h"

static void	term_fillcap_2(char **p)
{
	char	*t;

	t = tgetstr("kh", p);
	g_cap.key_home = ft_xstrdup(t ? t : "\033OH");
	t = tgetstr("@7", p);
	g_cap.key_end = ft_xstrdup(t ? t : "\033OF");
	t = tgetstr("kD", p);
	g_cap.key_delete = ft_xstrdup(t ? t : "\033[3~");
	t = tgetstr("kI", p);
	g_cap.key_insert = ft_xstrdup(t ? t : "\033[2~");
	t = tgetstr("ks", p);
	g_cap.kp_start = ft_xstrdup(t ? t : "\033[?1h\033=");
	t = tgetstr("ke", p);
	g_cap.kp_end = ft_xstrdup(t ? t : "\033[?1l\E>");
	t = tgetstr("kl", p);
	g_cap.key_left = ft_xstrdup(t ? t : "\033OD");
	t = tgetstr("kr", p);
	g_cap.key_right = ft_xstrdup(t ? t : "\033OC");
	t = tgetstr("ku", p);
	g_cap.key_up = ft_xstrdup(t ? t : "\033OA");
	t = tgetstr("kd", p);
	g_cap.key_down = ft_xstrdup(t ? t : "\033OB");
	g_cap.key_ctrl_left = ft_xstrdup("\033[1;5D");
	g_cap.key_ctrl_right = ft_xstrdup("\033[1;5C");
	g_cap.key_ctrl_up = ft_xstrdup("\033[1;5A");
}

void		term_fillcap(void)
{
	char		buf[TERM_BUFFER];
	char		*t;
	char		*p;

	p = buf;
	t = tgetstr("pc", &p);
	g_cap.pad_char = ft_xstrdup(t ? t : "\0");
	t = tgetstr("cr", &p);
	g_cap.car_ret = ft_xstrdup(t ? t : "\r");
	t = tgetstr("up", &p);
	g_cap.go_up = ft_xstrdup(t ? t : "\033[A");
	t = tgetstr("do", &p);
	g_cap.go_down = ft_xstrdup(t ? t : "\n");
	t = tgetstr("nd", &p);
	g_cap.go_right = ft_xstrdup(t ? t : "\033[C");
	t = tgetstr("le", &p);
	g_cap.go_left = ft_xstrdup(t ? t : "\b");
	t = tgetstr("cl", &p);
	g_cap.clear_all = ft_xstrdup(t ? t : "\033[H\033[2J");
	t = tgetstr("cd", &p);
	g_cap.clear_down = ft_xstrdup(t ? t : "\033[J");
	t = tgetstr("ce", &p);
	g_cap.clear_end = ft_xstrdup(t ? t : "\033[K");
	g_cap.key_ctrl_down = ft_xstrdup("\033[1;5B");
	term_fillcap_2(&p);
}

static void	clear_termcap_2(void)
{
	ft_strdel(&g_cap.key_ctrl_left);
	ft_strdel(&g_cap.key_ctrl_right);
	ft_strdel(&g_cap.key_ctrl_up);
	ft_strdel(&g_cap.key_ctrl_down);
}

void		clear_termcap(void)
{
	ft_strdel(&g_cap.pad_char);
	ft_strdel(&g_cap.car_ret);
	ft_strdel(&g_cap.go_up);
	ft_strdel(&g_cap.go_down);
	ft_strdel(&g_cap.go_right);
	ft_strdel(&g_cap.go_left);
	ft_strdel(&g_cap.clear_all);
	ft_strdel(&g_cap.clear_down);
	ft_strdel(&g_cap.clear_end);
	ft_strdel(&g_cap.kp_start);
	ft_strdel(&g_cap.kp_end);
	ft_strdel(&g_cap.key_home);
	ft_strdel(&g_cap.key_end);
	ft_strdel(&g_cap.key_delete);
	ft_strdel(&g_cap.key_insert);
	ft_strdel(&g_cap.key_left);
	ft_strdel(&g_cap.key_right);
	ft_strdel(&g_cap.key_up);
	ft_strdel(&g_cap.key_down);
	clear_termcap_2();
}
