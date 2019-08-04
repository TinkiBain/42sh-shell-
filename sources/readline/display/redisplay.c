/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redisplay.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelisan </var/spool/mail/vladimir>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/02 17:22:27 by gmelisan          #+#    #+#             */
/*   Updated: 2019/08/02 17:30:36 by gmelisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "display.h"

static int		max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

static void		print(t_buffer *newbuf, int pos)
{
	t_escseq	*es;

	if ((es = find_escseq(newbuf->escseqs, pos)))
		ft_fdprintf(STDOUT, "%s", es->str.s);
	if (str_get(newbuf->b, pos))
		ft_fdprintf(STDOUT, "%c", str_get(newbuf->b, pos));
	else
		ft_fdprintf(STDOUT, " ");
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
	return (max(oldlen, newlen));
}

/*
** Main redisplay loop. Now it just redraw all characters, even 
** if they are the same.
** TODO: skip repeated characters.
*/

void	redisplay(t_buffer *newbuf, int resize)
{
	int i;
	int j;
	int pos;

	move_cur_start();
	i = -1;
	pos = 0;
	while (++i < max(newbuf->out_rows, g_buffer.out_rows))
	{
		j = -1;
		while (++j < cols(newbuf, i))
		{
			print(newbuf, pos);
			if (pos % newbuf->out_cols == newbuf->out_cols - 1)
				move_cur_right(pos, newbuf->out_cols);
			pos++;
		}
	}
	if (resize)
		term_putstr("cd");	/* "ce" for linux. Should be at col 0. TODO fix later */	
	while (pos > newbuf->cpos)
		move_cur_left(pos--, newbuf->out_cols);
}
