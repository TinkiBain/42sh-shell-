/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forward_line.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelisan </var/spool/mail/vladimir>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/20 07:16:43 by gmelisan          #+#    #+#             */
/*   Updated: 2019/07/20 07:16:56 by gmelisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "actions.h"

void	forward_line(t_line *line)
{
	int w;
	int last_col_start;

	w = get_screenwidth();
	last_col_start = (line->str->len / w) * w;
	if (line->cpos >= last_col_start)
		return ;
	line->cpos += w;
	if (line->cpos > (int)line->str->len)
		line->cpos = line->str->len;
}
