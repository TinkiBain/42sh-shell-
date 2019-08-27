/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   self_insert.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelisan <gmelisan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/20 07:10:23 by gmelisan          #+#    #+#             */
/*   Updated: 2019/08/27 17:53:08 by wtalea           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "actions.h"

void	self_insert(t_line *line)
{
	int i;

	i = -1;
	if (line->arg > 1024)
		line->arg = 1024;
	while (++i < line->arg)
	{
		if (line->hs_mode)
		{
			str_xaddback(&line->hs.query, line->keybuf.s, 1);
			hs_find(line);
		}
		else
		{
			if (line->overwrite_mode && line->cpos < (int)line->str->len)
				line->str->s[line->cpos] = str_get(line->keybuf, 0);
			else
				str_xinsert(line->str, line->cpos, line->keybuf.s, 1);
			line->cpos++;
		}
	}
	if (!line->vi_mode)
		push_undo_list(line);
}
