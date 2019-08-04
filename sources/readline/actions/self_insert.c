/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   self_insert.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelisan </var/spool/mail/vladimir>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/20 07:10:23 by gmelisan          #+#    #+#             */
/*   Updated: 2019/07/30 02:54:31 by gmelisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "actions.h"

void	self_insert(t_line *line)
{
	if (line->hs_mode)
	{
		str_xaddback(&line->hs.query, line->keybuf, 1);
		hs_find(line);
	}
	else
	{
		if (line->overwrite_mode && line->cpos < (int)line->str->len)
			line->str->s[line->cpos] = *line->keybuf;
		else
			str_xinsert(line->str, line->cpos, line->keybuf, 1);
		line->cpos++;
	}
}
