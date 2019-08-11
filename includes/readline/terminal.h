/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   terminal.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelisan </var/spool/mail/vladimir>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/04 10:54:51 by gmelisan          #+#    #+#             */
/*   Updated: 2019/08/10 21:10:30 by gmelisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TERMINAL_H
# define TERMINAL_H

# include <unistd.h>
# include <termcap.h>
# include <sys/ioctl.h>
# include <termios.h>

# include "ft_readline.h"

# define DEFAULT_TERMTYPE	"xterm"
# define TERM_BUFFER		2048
# define KEY_BUF			32
# define ONECAP_BUFFER		32

typedef struct	s_cap
{
	char	*pad_char;
	char	*car_ret;
	char	*go_up;
	char	*go_down;
	char	*go_right;
	char	*go_left;
	char	*clear_all;
	char	*clear_down;
	char	*clear_end;
	char	*keypad_start;
	char	*keypad_end;
	char	*key_home;
	char	*key_end;
	char	*key_delete;
	char	*key_insert;
	char	*key_left;
	char	*key_right;
	char	*key_up;
	char	*key_down;
	char	*key_ctrl_left;
	char	*key_ctrl_right;
	char	*key_ctrl_up;
	char	*key_ctrl_down;
}				t_cap;

char	*term_getstr(char *str);
void	term_putstr(char *str);
void	term_init(void);
void	term_setup(void);
void	term_restore(void);

void	term_getpos(int *row, int *col);

extern struct termios	g_init_tios;
extern int				g_logfd;
extern t_cap			g_cap;

#endif
