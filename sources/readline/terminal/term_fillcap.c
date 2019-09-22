/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   term_fillcap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelisan <gmelisan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/25 20:28:45 by gmelisan          #+#    #+#             */
/*   Updated: 2019/09/22 19:15:03 by gmelisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "terminal.h"

static void	term_fillcap_2(char **p)
{
	g_cap.key_home = tgetstr("kh", p);
	g_cap.key_end = tgetstr("@7", p);
	g_cap.key_delete = tgetstr("kD", p);
	g_cap.key_insert = tgetstr("kI", p);
	g_cap.kp_start = tgetstr("ks", p);
	g_cap.kp_end = tgetstr("ke", p);
	g_cap.key_left = tgetstr("kl", p);
	g_cap.key_right = tgetstr("kr", p);
	g_cap.key_up = tgetstr("ku", p);
	g_cap.key_down = tgetstr("kd", p);
	g_cap.cur_hide = tgetstr("vi", p);
	g_cap.cur_show = tgetstr("ve", p);
}

void		term_fillcap(void)
{
	static char	buf[TERM_BUFFER];
	char		*p;
	char		*t;

	p = buf;
	t = tgetstr("pc", &p);
	g_cap.pad_char = ft_xstrdup(t ? t : "\0");
	t = tgetstr("cr", &p);
	g_cap.car_ret = ft_xstrdup(t ? t : "\r");
	t = tgetstr("do", &p);
	g_cap.go_down = ft_xstrdup(t ? t : "\n");
	t = tgetstr("le", &p);
	g_cap.go_left = ft_xstrdup(t ? t : "\b");
	g_cap.go_up = tgetstr("up", &p);
	g_cap.go_right = tgetstr("nd", &p);
	g_cap.clear_all = tgetstr("cl", &p);
	g_cap.clear_down = tgetstr("cd", &p);
	g_cap.clear_end = tgetstr("ce", &p);
	g_cap.key_ctrl_left = ft_xstrdup("\033[1;5D");
	g_cap.key_ctrl_right = ft_xstrdup("\033[1;5C");
	g_cap.key_ctrl_up = ft_xstrdup("\033[1;5A");
	g_cap.key_ctrl_down = ft_xstrdup("\033[1;5B");
	term_fillcap_2(&p);
}

void		clear_termcap(void)
{
	ft_strdel(&g_cap.pad_char);
	ft_strdel(&g_cap.car_ret);
	ft_strdel(&g_cap.go_down);
	ft_strdel(&g_cap.go_left);
	ft_strdel(&g_cap.key_ctrl_left);
	ft_strdel(&g_cap.key_ctrl_right);
	ft_strdel(&g_cap.key_ctrl_up);
	ft_strdel(&g_cap.key_ctrl_down);
}
