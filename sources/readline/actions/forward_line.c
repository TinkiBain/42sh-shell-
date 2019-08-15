/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forward_line.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelisan </var/spool/mail/vladimir>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/20 07:16:43 by gmelisan          #+#    #+#             */
/*   Updated: 2019/08/15 06:27:37 by gmelisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "actions.h"

void	forward_line(t_line *line)
{
	int w;
	int last_col_start;
	int i;

	i = -1;
	while (++i < line->arg)
	{
		w = get_screen_width();
		last_col_start = (line->str->len / w) * w;
		if (line->cpos >= last_col_start)
			return ;
		line->cpos += w;
		if (line->cpos > (int)line->str->len)
			line->cpos = line->str->len;
	}
}
