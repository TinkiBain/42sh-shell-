/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   terminal.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jterry <jterry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/04 10:37:33 by gmelisan          #+#    #+#             */
/*   Updated: 2019/10/30 20:23:24 by gmelisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "terminal.h"
#include "utils.h"

struct termios	g_init_tios;
t_cap			g_cap;
int				g_term_broken;
extern t_opt	g_opt;

void			term_init(void)
{
	char		*termtype;
	static char	term_buffer[TERM_BUFFER];

	termtype = get_var_value("TERM");
	if (tgetent(term_buffer, termtype) <= 0)
	{
		loginfo("Failed to open TERM='%s'. Using default.", termtype);
		if (tgetent(term_buffer, DEFAULT_TERMTYPE) <= 0)
		{
			loginfo("Failed to open default terminal (%s).", DEFAULT_TERMTYPE);
			ft_putstr_fd("Error while fetching terminal info. "
							"Correct operation is not guaranteed.\n", STDERR);
		}
		else
			loginfo("Terminal type: %s", DEFAULT_TERMTYPE);
	}
	else
		loginfo("Terminal type: %s", termtype);
}

void			term_putstr(char *str)
{
	int ret;

	if (!str)
		return ;
	ret = tputs(str, 1, ft_putint);
	if (ret < 0)
		ft_putstr_fd(str, g_opt.rl_out);
}

void			term_save(void)
{
	tcgetattr(g_opt.rl_in, &g_init_tios);
}

void			term_setup(void)
{
	struct termios	work_tios;

	term_fillcap();
	PC = *g_cap.pad_char;
	BC = g_cap.go_left;
	UP = g_cap.go_up;
	term_putstr(g_cap.kp_start);
	work_tios = g_init_tios;
	work_tios.c_oflag = 0;
	work_tios.c_oflag |= OPOST | ONLCR;
	work_tios.c_lflag &= ~(ICANON | ECHO | ISIG);
	work_tios.c_cc[VMIN] = 1;
	work_tios.c_cc[VTIME] = 0;
	if (tcsetattr(g_opt.rl_in, TCSANOW, &work_tios) < 0)
		tcsetattr(g_opt.rl_in, TCSANOW, &work_tios);
	ospeed = work_tios.c_ospeed;
	g_term_broken = 1;
}

void			term_restore(void)
{
	if (g_term_broken)
	{
		// term_putstr(g_cap.kp_end);
		// term_putstr(g_cap.cur_show);
		tcsetattr(g_opt.rl_in, TCSANOW, &g_init_tios);
		clear_termcap();
		g_term_broken = 0;
	}
}

/*
** About normal and application modes:
**
** https://unix.stackexchange.com/questions/139744/
** how-to-enable-control-key-combinations-for-gnu-screen-on-putty
**
** https://invisible-island.net/xterm/manpage/xterm.html#h3-Special-Keys
*/
