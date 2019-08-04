/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   previous_history.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelisan </var/spool/mail/vladimir>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/20 07:14:30 by gmelisan          #+#    #+#             */
/*   Updated: 2019/07/20 07:14:47 by gmelisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "actions.h"

void	previous_history(t_line *line)
{
	if (line->history->item->prev)
	{
		line->history->item = line->history->item->prev;
		line->str = (t_string *)line->history->item->content;
		line->cpos = line->str->len;
	}
}
