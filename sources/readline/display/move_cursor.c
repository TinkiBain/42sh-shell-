/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_cursor.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelisan <gmelisan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/02 17:24:53 by gmelisan          #+#    #+#             */
/*   Updated: 2019/08/27 17:03:31 by gmelisan         ###   ########.fr       */
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
		term_putstr(g_cap.go_up);
	term_putstr(g_cap.car_ret);
}

void		move_cur_right(int oldpos, int width)
{
	int	oldccol;

	oldccol = oldpos % width;
	if (oldccol == width - 1)
		move_cur_nl();
	else
		term_putstr(g_cap.go_right);
}

void		move_cur_left(int oldpos, int width)
{
	int	oldccol;
	int	i;

	oldccol = oldpos % width;
	if (oldccol == 0)
	{
		term_putstr(g_cap.go_up);
		i = -1;
		while (++i < width - 1)
			term_putstr(g_cap.go_right);
	}
	else
		term_putstr(g_cap.go_left);
}

void		move_cur_nl(void)
{
	term_putstr(g_cap.go_down);
	term_putstr(g_cap.car_ret);
}

void		move_cur_to(int oldpos, int newpos, int width)
{
	int cur_col;
	int tar_col;
	int row_diff;
	int i;

	cur_col = oldpos % width;
	tar_col = newpos % width;
	row_diff = newpos / width - oldpos / width;
	row_diff = row_diff > 0 ? row_diff : -row_diff;
	i = -1;
	while (++i < row_diff)
		term_putstr(newpos > oldpos ? g_cap.go_down : g_cap.go_up);
	if (cur_col > tar_col)
		while (cur_col != tar_col)
		{
			term_putstr(g_cap.go_left);
			cur_col--;
		}
	else
		while (cur_col != tar_col)
		{
			term_putstr(g_cap.go_right);
			cur_col++;
		}
}
