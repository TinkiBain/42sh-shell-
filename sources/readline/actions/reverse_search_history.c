/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_search_history.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelisan </var/spool/mail/vladimir>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/26 21:37:14 by gmelisan          #+#    #+#             */
/*   Updated: 2019/07/30 20:14:22 by gmelisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "actions.h"

void	reverse_search_history(t_line *line)
{
	line->hs_mode = 1;
	if (!line->hs.hist_start)
	{
		line->hs.query = str_xcreate(0);
		line->hs.hist_start = line->history->item;
		line->hs.hist_current = line->hs.hist_start;
		line->hs.original_cpos = line->cpos;
		/* line->hs.query_pos = line->cpos; */
		line->hs.query_pos = -1;
		line->hs.success = 1;
	}
	else
		hs_prev(line);
}
