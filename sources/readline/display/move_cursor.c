/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_cursor.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelisan </var/spool/mail/vladimir>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/02 17:24:53 by gmelisan          #+#    #+#             */
/*   Updated: 2019/08/11 04:54:59 by gmelisan         ###   ########.fr       */
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
		tputs(g_cap.go_up, 1, ft_putint);
	tputs(g_cap.car_ret, 1, ft_putint);
}

void		move_cur_right(int oldpos, int width)
{
	int	oldccol;

	oldccol = oldpos % width;
	if (oldccol == width - 1)
	{
		tputs(g_cap.go_down, 1, ft_putint);
		tputs(g_cap.car_ret, 1, ft_putint);
	}
	else
		tputs(g_cap.go_right, 1, ft_putint);
}

void		move_cur_left(int oldpos, int width)
{
	int	oldccol;
	int	i;

	oldccol = oldpos % width;
	if (oldccol == 0)
	{
		tputs(g_cap.go_up, 1, ft_putint);
		i = -1;
		while (++i < width - 1)
			tputs(g_cap.go_right, 1, ft_putint);
	}
	else
		tputs(g_cap.go_left, 1, ft_putint);
}

void		move_cur_nl(void)
{
	tputs(g_cap.go_down, 1, ft_putint);
	tputs(g_cap.car_ret, 1, ft_putint);
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
		tputs((newpos > oldpos ? g_cap.go_down : g_cap.go_up), 1, ft_putint);
	if (cur_col > tar_col)
		while (cur_col != tar_col)
		{
			tputs(g_cap.go_left, 1, ft_putint);
			cur_col--;
		}
	else
		while (cur_col != tar_col)
		{
			tputs(g_cap.go_right, 1, ft_putint);
			cur_col++;
		}
}
