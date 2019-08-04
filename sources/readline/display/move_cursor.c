/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_cursor.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelisan </var/spool/mail/vladimir>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/02 17:24:53 by gmelisan          #+#    #+#             */
/*   Updated: 2019/08/02 17:39:08 by gmelisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "display.h"

void		move_cur_start(void)
{
	int crow;
	int ccol;
	int i;

	crow = g_buffer.cpos / g_buffer.out_cols;
	ccol = g_buffer.cpos % g_buffer.out_cols;
	i = -1;
	while (++i < crow)
		term_putstr("up");
	/* i = -1; */
	/* while (++i < ccol) */
	/* 	term_putstr("le"); */
	term_putstr("cr");
}

/* int			move_first_new(t_buffer *newbuf) */
/* { */
/* 	int		pos1; */
/* 	int		pos2; */
/* 	int		i; */

/* 	pos1 = -1; */
/* 	while (++pos1 < newbuf->b.len) */
/* 		if (str_get(newbuf->b, pos1) != str_get(g_buffer->b, pos1)) */
/* 			break ; */
/* 	i = -1; */
/* 	while (++i < newbuf->escseqs.len) */
/* 		if (!ft_strequ(((t_escseq *)vec_get(newbuf->escseqs, i))->str.s, */
/* 					   ((t_escseq *)vec_get(g_buffer->escseqs, i))->str.s)) */
/* 			break ; */
/* } */

void		move_cur_right(int oldpos, int width)
{
	int	oldccol;

	oldccol = oldpos % width;
	if (oldccol == width - 1)
	{
		term_putstr("do");
		term_putstr("cr");
	}
	else
		term_putstr("nd");
}

void		move_cur_left(int oldpos, int width)
{
	int	oldccol;
	int	i;

	oldccol = oldpos % width;
	if (oldccol == 0)
	{
		term_putstr("up");
		i = -1;
		while (++i < width - 1)
			term_putstr("nd");
	}
	else
		term_putstr("le");
}
