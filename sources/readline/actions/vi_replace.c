/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vi_replace.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelisan <gmelisan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/15 12:25:08 by gmelisan          #+#    #+#             */
/*   Updated: 2019/10/14 18:39:32 by gmelisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "actions.h"

static void	vi_replace_char(t_line *line, char c)
{
	int		i;
	int		j;

	if (ft_isprint(c))
	{
		i = 0;
		j = line->cpos;
		while (i < line->arg && str_get(*line->str, j))
		{
			line->str->s[j] = c;
			i++;
			j++;
		}
		line->cpos = j - 1;
		if (line->cpos < 0)
			line->cpos = 0;
	}
}

void		vi_replace(t_line *line)
{
	int				ret;
	char			c;
	extern t_opt	g_opt;

	ret = read(g_opt.rl_in, &c, 1);
	if (ret < 0)
		loginfo("vi_replace(): read error");
	if (c == CTRL_C)
		reset_line(line);
	else
		vi_replace_char(line, c);
}
