/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redisplay.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelisan <gmelisan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/02 17:22:27 by gmelisan          #+#    #+#             */
/*   Updated: 2019/09/13 12:28:09 by gmelisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "display.h"

/*
** From the comment of original readline library rewriting character is
** faster than getting/sending sequence to move cursor forward.
** (readline-8.0, display.c:2468, inside _rl_move_cursor_relative)
*/

static void		print(t_buffer *newbuf, int pos)
{
	t_escseq		*es;
	extern t_opt	g_opt;

	if ((es = find_escseq(newbuf->escseqs, pos)))
		ft_fdprintf(g_opt.rl_out, "%s", es->str.s);
	if (str_get(newbuf->b, pos))
		ft_fdprintf(g_opt.rl_out, "%c", str_get(newbuf->b, pos));
	else
		ft_fdprintf(g_opt.rl_out, " ");
	if (pos % newbuf->out_cols == newbuf->out_cols - 1)
		move_cur_nl();
}

/*
** Count how many times we need to step in inner loop of redisplay.
** We need this checks when resizing.
** Also we get maximum value of old and new buf's lens because
** when our new buffer is lesser then old, we need to clear
** remainings from old.
*/

static int		cols(t_buffer *newbuf, int i)
{
	t_string	*old;
	t_string	*new;
	int			newlen;
	int			oldlen;

	old = (i < newbuf->out_rows && i >= 0 ? &newbuf->out[i] : NULL);
	new = (i < g_buffer.out_rows && i >= 0 ? &g_buffer.out[i] : NULL);
	oldlen = old ? old->len : 0;
	newlen = new ? new->len : 0;
	return (max_int(oldlen, newlen));
}

static int		skip_row_if_equal(t_buffer *newbuf, int *pos)
{
	int			i;
	int			vpos;

	i = -1;
	vpos = *pos;
	while (++i < g_buffer.out_cols)
	{
		if (str_get(newbuf->b, vpos) != str_get(g_buffer.b, vpos))
			return (0);
		vpos++;
	}
	if (escseq_test_unmatch(g_buffer.escseqs, newbuf->escseqs, *pos, vpos - 1))
		return (0);
	i = -1;
	*pos = vpos;
	return (1);
}

/*
** Main redisplay loop.
** if (resize == 1) it redraws all non-unique rows in buffer + last row.
** else just redraws all buffer.
**
** TODO: now it always redisplays last row, it's not good. Idk how to fix it and
** don't break everything else.
*/

void			redisplay(t_buffer *newbuf)
{
	int i;
	int j;
	int pos;
	int oldpos;
	int	m;

	oldpos = g_buffer.cpos;
	pos = 0;
	m = max_int(newbuf->out_rows, g_buffer.out_rows);
	i = -1;
	while (++i < m)
	{
		if ((i + 1 == m ? 0 : 1) && skip_row_if_equal(newbuf, &pos))
			continue ;
		move_cur_to(oldpos, pos, newbuf->out_cols);
		j = -1;
		while (++j < cols(newbuf, i) + 1)
		{
			print(newbuf, pos);
			pos++;
		}
		oldpos = pos;
	}
	move_cur_to(pos, newbuf->cpos, newbuf->out_cols);
}

void			resize(t_buffer *newbuf, int first)
{
	int i;
	int j;
	int pos;

	if (!first)
		move_cur_start();
	pos = 0;
	i = -1;
	while (++i < max_int(newbuf->out_rows, g_buffer.out_rows))
	{
		j = -1;
		while (++j < cols(newbuf, i) + 1)
		{
			print(newbuf, pos);
			pos++;
		}
	}
	term_putstr(g_cap.clear_down);
	while (pos > newbuf->cpos)
		move_cur_left(pos--, newbuf->out_cols);
}
