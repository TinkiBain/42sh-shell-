/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   previous_history.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelisan <gmelisan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/20 07:14:30 by gmelisan          #+#    #+#             */
/*   Updated: 2019/08/15 06:31:19 by gmelisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "actions.h"

void	previous_history(t_line *line)
{
	int i;

	i = -1;
	while (++i < line->arg)
	{
		if (line->history->item->prev)
		{
			line->history->item = line->history->item->prev;
			line->str = (t_string *)line->history->item->content;
			line->cpos = line->str->len;
		}
	}
}
