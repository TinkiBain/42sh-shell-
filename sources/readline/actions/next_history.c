/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   next_history.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelisan <gmelisan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/20 07:14:54 by gmelisan          #+#    #+#             */
/*   Updated: 2019/10/13 12:39:12 by gmelisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "actions.h"

void	next_history(t_line *line)
{
	int i;

	i = -1;
	while (++i < line->arg)
	{
		if (line->history->item->next)
		{
			line->history->item = line->history->item->next;
			line->str = (t_string *)line->history->item->content;
			line->cpos = line->str->len;
		}
	}
}
