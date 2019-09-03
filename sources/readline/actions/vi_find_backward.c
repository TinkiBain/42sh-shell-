/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vi_find_backward.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelisan <gmelisan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/15 11:45:34 by gmelisan          #+#    #+#             */
/*   Updated: 2019/09/01 16:41:37 by gmelisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "actions.h"

void	vi_find_backward_char(t_line *line, char c)
{
	int		i;
	int		j;

	if (ft_isprint(c))
	{
		j = -1;
		while (++j < line->arg)
		{
			i = line->cpos;
			while (str_get(*line->str, --i))
				if (str_get(*line->str, i) == c)
				{
					line->cpos = i;
					break ;
				}
		}
	}
}

void	vi_find_backward(t_line *line)
{
	int				ret;
	char			c;
	extern t_opt	g_opt;

	ret = read(g_opt.rl_in, &c, 1);
	if (ret < 0)
		loginfo("vi_find_backward(): read error");
	if (c == CTRL_C)
		reset_line(line);
	else if (ft_isprint(c))
	{
		line->vi.prev_find = VI_FIND_BACKWARD;
		line->vi.prev_find_c = c;
		vi_find_backward_char(line, c);
	}
}
