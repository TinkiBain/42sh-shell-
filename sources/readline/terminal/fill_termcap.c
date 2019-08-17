/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_termcap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelisan </var/spool/mail/vladimir>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/17 05:47:53 by gmelisan          #+#    #+#             */
/*   Updated: 2019/08/17 08:01:41 by gmelisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "terminal.h"

static void	term_fillcap_2(char **p)
{
	char	*t;

	g_cap.key_left = ft_xstrdup((t = tgetstr("kl", p)) ? t : "\033OD");
	g_cap.key_right = ft_xstrdup((t = tgetstr("kr", p)) ? t : "\033OC");
	g_cap.key_up = ft_xstrdup((t = tgetstr("ku", p)) ? t : "\033OA");
	g_cap.key_down = ft_xstrdup((t = tgetstr("kd", p)) ? t : "\033OB");
	g_cap.key_ctrl_left = ft_xstrdup("\033[1;5D");
	g_cap.key_ctrl_right = ft_xstrdup("\033[1;5C");
	g_cap.key_ctrl_up = ft_xstrdup("\033[1;5A");
	g_cap.key_ctrl_down = ft_xstrdup("\033[1;5B");
}

void		term_fillcap(void)
{
	char		buf[TERM_BUFFER];
	char		*t;
	char		*p;

	p = buf;
	g_cap.pad_char = ft_xstrdup((t = tgetstr("pc", &p)) ? t : "\0");
	g_cap.car_ret = ft_xstrdup((t = tgetstr("cr", &p)) ? t : "\r");
	g_cap.go_up = ft_xstrdup((t = tgetstr("up", &p)) ? t : "\033[A");
	g_cap.go_down = ft_xstrdup((t = tgetstr("do", &p)) ? t : "\n");
	g_cap.go_right = ft_xstrdup((t = tgetstr("nd", &p)) ? t : "\033[C");
	g_cap.go_left = ft_xstrdup((t = tgetstr("le", &p)) ? t : "\b");
	g_cap.clear_all = ft_xstrdup((t = tgetstr("cl", &p)) ? t : "\033[H\033[2J");
	g_cap.clear_down = ft_xstrdup((t = tgetstr("cd", &p)) ? t : "\033[J");
	g_cap.clear_end = ft_xstrdup((t = tgetstr("ce", &p)) ? t : "\033[K"); 
	g_cap.key_home = ft_xstrdup((t = tgetstr("kh", &p)) ? t : "\033OH");
	g_cap.key_end = ft_xstrdup((t = tgetstr("@7", &p)) ? t : "\033OF");
	g_cap.key_delete = ft_xstrdup((t = tgetstr("kD", &p)) ? t : "\033[3~");
	g_cap.key_insert = ft_xstrdup((t = tgetstr("kI", &p)) ? t : "\033[2~");
	g_cap.kp_start = ft_xstrdup((t = tgetstr("ks", &p)) ? t : "\033[?1h\033=");
	g_cap.kp_end = ft_xstrdup((t = tgetstr("ke", &p)) ? t : "\033[?1l\E>");
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
