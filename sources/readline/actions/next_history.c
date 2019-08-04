/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   next_history.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelisan </var/spool/mail/vladimir>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/20 07:14:54 by gmelisan          #+#    #+#             */
/*   Updated: 2019/07/20 07:15:06 by gmelisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "actions.h"

void	next_history(t_line *line)
{
	if (line->history->item->next)
	{
		line->history->item = line->history->item->next;
		line->str = (t_string *)line->history->item->content;
		line->cpos = line->str->len;
	}
}
