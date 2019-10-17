/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggwin-go <ggwin-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/04 11:28:08 by gmelisan          #+#    #+#             */
/*   Updated: 2019/10/17 16:41:35 by gmelisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DISPLAY_H
# define DISPLAY_H

# include "ft_readline.h"
# include "terminal.h"

# define TERM_MAX_COL		2048

typedef struct	s_buffer
{
	t_string	original;
	t_string	b;
	t_vector	escseqs;
	int			cpos;
	int			shift_cpos;
	int			prompt_len;
	int			prompt_full_len;
	t_string	*out;
	int			out_rows;
	int			out_cols;
}				t_buffer;

extern t_buffer	g_buffer;

void			init_linebuf(t_line *line);
void			clear_linebuf(void);
void			update_line(t_line *line, int first);
t_string		*build_bufout(t_string str, int width);
void			redisplay(t_buffer *newbuf);
void			resize(t_buffer *newbuf, int first);
int				get_screen_width(void);
int				get_screen_height(void);
int				get_term_cols(void);

void			move_cur_nl(void);
void			move_cursor(int oldpos, int newpos, int width);

void			colorize(t_string *str, int start, int cpos);
int				colorize_alpha(t_string *str, int *i);
int				colorize_cmd_sep(t_string *str, int i, char *color, int *cpos);
int				colorize_arg(t_string *str, int i, char *color, int *cpos);
int				colorize_paren(t_string *str, int i, char *color);

#endif
