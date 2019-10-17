/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   terminal.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggwin-go <ggwin-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/04 10:54:51 by gmelisan          #+#    #+#             */
/*   Updated: 2019/10/17 15:47:40 by gmelisan         ###   ########.fr       */
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

typedef struct			s_cap
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
	char	*kp_start;
	char	*kp_end;
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
	char	*cur_hide;
	char	*cur_show;
}						t_cap;

char					*term_getstr(char *str);
void					term_putstr(char *str);
void					term_init(void);
void					term_setup(void);
void					term_restore(void);
void					term_fillcap(void);
void					clear_termcap(void);
void					term_putstr(char *str);

int						term_getpos(int *row, int *col);

extern struct termios	g_init_tios;
extern int				g_logfd;
extern t_cap			g_cap;

#endif
