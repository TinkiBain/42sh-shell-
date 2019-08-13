/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_completions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelisan <gmelisan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/07 19:11:04 by gmelisan          #+#    #+#             */
/*   Updated: 2019/08/13 06:52:57 by gmelisan         ###   ########.fr       */
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

static void	show(t_vector vec)
{
	int max_filename;
	int columns;
	int jump;
	int row;
	int i;

	term_restore();
	columns = get_screen_width() / (max_filename = get_max_filename(vec) + 1);
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

static int	ask_display_many(int n)
{
	char	c;

	if (n < COMPLETION_QUERY_ITEMS)
		return (1);
	ft_fdprintf(STDOUT, "\n\rDisplay all %d possibilities? (y or n)", n);
	c = 0;
	while (c != CTRL_C && c != 'n' && c != DEL)
	{
		read(STDIN, &c, 1);
		if (c == 'y' || c == ' ')
			return (1);
	}
	return (0);
}

void		show_completions(t_vector vec)
{
	if (ask_display_many(vec.len))
		show(vec);
	else
		ft_putstr_fd("\n\r", STDOUT);
}
