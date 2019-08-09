/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   terminal.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggwin-go <ggwin-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/04 10:37:33 by gmelisan          #+#    #+#             */
/*   Updated: 2019/08/09 22:02:08 by ggwin-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "terminal.h"

struct termios	g_init_tios;

static int	ft_putint(int c)
{
	write(STDOUT, &c, 1);
	return (0);
}

char		*term_getstr(char *str)
{
	static char	buf[ONECAP_BUFFER];
	char		**pb;

	ft_bzero(buf, ONECAP_BUFFER);
	pb = (char **)&buf;
	return (tgetstr(str, pb));
}

void		term_putstr(char *str)
{
	tputs(term_getstr(str), 1, ft_putint);
}

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
		g_errno = ERROR_TERMCAP;
	if (ret == 0)
		g_errno = ERROR_UNK_TERMTYPE;
}

void	term_setup(void)
{
	char *temp;
	struct termios work_tios;

	temp = term_getstr("pc");
	PC = temp ? *temp : 0;
	BC = term_getstr("le");
	UP = term_getstr("up");
	term_putstr("ks");

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
	term_putstr("ke");
	ft_putstr_fd("\n", STDOUT);
	term_putstr("cd");
}

/*
** Not in use, for debug only
*/

void	term_getpos(int *row, int *col)
{
	char	buf[ONECAP_BUFFER];
	int		i;

	*row = 0;
	*col = 0;
	bzero(buf, ONECAP_BUFFER);
	term_putstr("u7");
	read(STDIN, buf, ONECAP_BUFFER - 1);
	*row = ft_atoi(buf + 2) - 1;
	i = 0;
	while (i < ONECAP_BUFFER && buf[i] != ';')
		i++;
	*col = ft_atoi(buf + ++i) - 1;
}

/*
** About normal and application modes:
**
** https://unix.stackexchange.com/questions/139744/
** how-to-enable-control-key-combinations-for-gnu-screen-on-putty
**
** https://invisible-island.net/xterm/manpage/xterm.html#h3-Special-Keys
*/
