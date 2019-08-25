/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backward_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelisan <gmelisan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/20 07:16:18 by gmelisan          #+#    #+#             */
/*   Updated: 2019/08/15 06:25:36 by gmelisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "actions.h"

void	backward_line(t_line *line)
{
	int w;
	int i;

	i = -1;
	while (++i < line->arg)
	{
		w = get_screen_width();
		if (line->cpos < w - (int)line->prompt.len)
			return ;
		line->cpos -= w;
		if (line->cpos < 0)
			line->cpos = 0;
	}
}
