/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   terminal.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggwin-go <ggwin-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/04 10:37:33 by gmelisan          #+#    #+#             */
/*   Updated: 2019/08/14 17:53:09 by gmelisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "terminal.h"

struct termios	g_init_tios;
t_cap			g_cap;

static	void	term_fillcap_2(char **p)
{
	g_cap.key_left = tgetstr("kl", p);
	g_cap.key_right = tgetstr("kr", p);
	g_cap.key_up = tgetstr("ku", p);
	g_cap.key_down = tgetstr("kd", p);
	g_cap.key_ctrl_left = ft_strdup("\033[1;5D");
	g_cap.key_ctrl_right = ft_strdup("\033[1;5C");
	g_cap.key_ctrl_up = ft_strdup("\033[1;5A");
	g_cap.key_ctrl_down = ft_strdup("\033[1;5B");
}

void		term_fillcap(void)
{
	static char	buf[TERM_BUFFER];
	char		*p;

	p = buf;
	g_cap.pad_char = tgetstr("pc", &p);
	g_cap.car_ret = tgetstr("cr", &p);
	g_cap.go_up = tgetstr("up", &p);
	g_cap.go_down = tgetstr("do", &p);
	g_cap.go_right = tgetstr("nd", &p);
	g_cap.go_left = tgetstr("le", &p);
	g_cap.clear_all = tgetstr("cl", &p);
	g_cap.clear_down = tgetstr("cd", &p);
	g_cap.clear_end = tgetstr("ce", &p);
	g_cap.key_home = tgetstr("kh", &p);
	g_cap.key_end = tgetstr("@7", &p);
	g_cap.key_delete = tgetstr("kD", &p);
	g_cap.key_insert = tgetstr("kI", &p);
	g_cap.keypad_start = tgetstr("ks", &p);
	g_cap.keypad_end = tgetstr("ke", &p);
	term_fillcap_2(&p);
}

/* void		term_putstr(char *str) */
/* { */
/* 	tputs(term_getstr(str), 1, ft_putint); */
/* } */

void		term_init(void)
{
	int			ret;
	char		*termtype;
	static char	term_buffer[TERM_BUFFER];
	int			needfree;

	needfree = 0;
	termtype = getenv("TERM");
	if (!termtype)
	{
		termtype = ft_xmemalloc(ft_strlen(DEFAULT_TERMTYPE) + 1);
		ft_strcpy(termtype, DEFAULT_TERMTYPE);
		needfree = 1;
	}
	loginfo("Terminal type: %s", termtype);
	ret = tgetent(term_buffer, termtype);
	if (needfree)
		free(termtype);
	if (ret < 0)
		g_errno = E_TERMCAP;
	if (ret == 0)
		g_errno = E_UNK_TERMTYPE;
}

void	term_setup(void)
{
	char *temp;
	struct termios work_tios;

	term_fillcap();
	temp = g_cap.pad_char;
	PC = temp ? *temp : 0;
	BC = g_cap.go_left;
	UP = g_cap.go_up;
	tputs(g_cap.keypad_start, 1, ft_putint);
	;
	tcgetattr(STDIN, &g_init_tios);
	work_tios = g_init_tios;
	work_tios.c_oflag &= ~OPOST;
	work_tios.c_lflag &= ~(ICANON | ECHO | ISIG);
	work_tios.c_cc[VMIN] = 1;
	work_tios.c_cc[VTIME] = 0;
	tcsetattr(STDIN, TCSANOW, &work_tios);
	ospeed = work_tios.c_ospeed;
}

void	term_restore(void)
{
	tcsetattr(STDIN, TCSANOW, &g_init_tios);
	tputs(g_cap.keypad_end, 1, ft_putint);
	ft_putstr_fd("\n", STDOUT);
	tputs(g_cap.clear_down, 1, ft_putint); /* TODO column 0 fix later */
	ft_strdel(&g_cap.key_ctrl_left);
	ft_strdel(&g_cap.key_ctrl_right);
	ft_strdel(&g_cap.key_ctrl_up);
	ft_strdel(&g_cap.key_ctrl_down);
}

/*
** About normal and application modes:
**
** https://unix.stackexchange.com/questions/139744/
** how-to-enable-control-key-combinations-for-gnu-screen-on-putty
**
** https://invisible-island.net/xterm/manpage/xterm.html#h3-Special-Keys
**
**
** Default sequences:
**
**  key					termcap			terminfo		sequence
** --------------------------------------------------------------
** app_mode on			ks				smkx			\E[?1h\E=
** app_mode off			ke				rmkx			\E[?1l\E>
** 
** arrow_left			kl				kcub1			\EOD
** arrow_right			kr				kcuf1			\EOC
** arrow_up				ku				kcuu1			\EOA
** arrow_down			kd				kcud1			\EOB
**
** go_left				le				cub1			\b
** go_right				nd				cuf1			\E[C
** go_up				up				cuu1			\E[A
** go_down				do				cud1			\n
**
** delete				kD				kdch1			\E[3~
** insert				kI				kich1			\E[2~
** home					kh				khome			\EOH
** end					@7				kend			\EOF
**
** save cursor pos		sc				sc				\E7
** restore cursor pos	rc				rc				\E8	
*/
