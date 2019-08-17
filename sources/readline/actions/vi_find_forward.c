/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vi_find_forward.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelisan </var/spool/mail/vladimir>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/15 11:34:39 by gmelisan          #+#    #+#             */
/*   Updated: 2019/08/17 17:15:38 by gmelisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "actions.h"

void	vi_find_forward_char(t_line *line, char c)
{
	int		i;
	int		j;

	if (ft_isprint(c))
	{
		j = -1;
		while (++j < line->arg)
		{
			i = line->cpos;
			while (str_get(*line->str, ++i))
				if (str_get(*line->str, i) == c)
				{
					line->cpos = i;
					break ;
				}
		}
	}
}


void	vi_find_forward(t_line *line)
{
	int		ret;
	char	c;

	ret = read(STDIN, &c, 1);
	if (ret < 0)
		loginfo("vi_find_forward(): read error");
	if (c == CTRL_C)
		reset_line(line);
	else if (ft_isprint(c))
	{
		line->vi.prev_find = VI_FIND_FORWARD;
		line->vi.prev_find_c = c;
		vi_find_forward_char(line, c);
	}
}
