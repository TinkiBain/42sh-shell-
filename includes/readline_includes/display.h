/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelisan </var/spool/mail/vladimir>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/04 11:28:08 by gmelisan          #+#    #+#             */
/*   Updated: 2019/08/02 17:38:39 by gmelisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DISPLAY_H
# define DISPLAY_H

# include "ft_readline.h"

# define TERM_MAX_COL		2048

typedef struct	s_buffer
{
	t_string	original;
	t_string	b;
	t_vector	escseqs;
	int			cpos;
	int			prompt_len;
	t_string	*out;
	int			out_rows;
	int			out_cols;
}				t_buffer;

extern t_buffer	g_buffer;

void			init_linebuf(t_line *line);
void			clear_linebuf(void);
void			update_line(t_line *line);
t_string		*build_bufout(t_string str, int width);
void			redisplay(t_buffer *newbuf, int resize);
int				get_screenwidth(void);
int				get_term_cols(void);

void			move_cur_start(void);
void			move_cur_left(int oldpos, int width);
void			move_cur_right(int oldpos, int width);

#endif
