/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_completions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelisan <gmelisan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/07 19:11:04 by gmelisan          #+#    #+#             */
/*   Updated: 2019/08/07 21:07:48 by gmelisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "show_completions.h"

static int	get_max_filename(t_vector vec)
{
	int			i;
	t_string	*str;
	int			max;

	max = 0;
	i = 0;
	while ((str = vec_get(vec, i)))
	{
		if ((int)str->len > max)
			max = str->len;
		i++;
	}
	return (max);
}

static void	show_one(t_string *str, int max)
{
	int i;

	ft_putstr_fd(str->s, STDOUT);
	i = str->len;
	while (i++ < max)
		ft_putchar_fd(' ', STDOUT);
}

void		show_completions(t_vector vec)
{
	int max_filename;
	int columns;
	int jump;
	int row;
	int i;

	term_restore();
	columns = get_screenwidth() / (max_filename = get_max_filename(vec) + 1);
	jump = vec.len / columns;
	if (vec.len % columns)
		jump++;
	row = 0;
	while (row < jump)
	{
		i = row;
		while (i < (int)vec.len)
		{
			show_one(vec_get(vec, i), max_filename);
			i += jump;
		}
		ft_putchar_fd('\n', STDOUT);
		row++;
	}
	term_setup();
}
