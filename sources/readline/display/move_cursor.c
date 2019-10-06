/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_cursor.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelisan <gmelisan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/02 17:24:53 by gmelisan          #+#    #+#             */
/*   Updated: 2019/09/23 17:23:22 by gmelisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "display.h"

void		move_cur_nl(void)
{
	term_putstr(g_cap.go_down);
	term_putstr(g_cap.car_ret);
}

static void	move_horizontal(int cur_col, int tar_col)
{
	if (tar_col == 0 && !g_cap.go_left)
		term_putstr(g_cap.car_ret);
	else if (cur_col > tar_col)
		while (cur_col != tar_col)
		{
			term_putstr(g_cap.go_left);
			cur_col--;
		}
	else if (cur_col < tar_col)
		while (cur_col != tar_col)
		{
			term_putstr(g_cap.go_right);
			cur_col++;
		}
}

void		move_cursor(int oldpos, int newpos, int width)
{
	int cur_col;
	int tar_col;
	int row_diff;
	int i;

	cur_col = oldpos % width;
	tar_col = newpos % width;
	row_diff = ft_abs(newpos / width - oldpos / width);
	i = -1;
	while (++i < row_diff)
		term_putstr(newpos > oldpos ? g_cap.go_down : g_cap.go_up);
	move_horizontal(cur_col, tar_col);
}
