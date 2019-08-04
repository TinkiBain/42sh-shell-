/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reset_history_search.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelisan </var/spool/mail/vladimir>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/30 03:29:20 by gmelisan          #+#    #+#             */
/*   Updated: 2019/07/30 19:16:04 by gmelisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "actions.h"

void	reset_history_search(t_line *line)
{
	if (line->hs_mode)
	{
		line->history->item = line->hs.hist_start;
		line->str = (t_string *)line->history->item->content;
		line->cpos = line->hs.original_cpos;
		str_delete(&line->hs.query);
		line->hs.hist_start = NULL;
		line->hs.hist_current = NULL;
		line->hs_mode = 0;
	}
	else
		reset_line(line);
}
