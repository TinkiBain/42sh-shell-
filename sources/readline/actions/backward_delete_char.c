/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backward_delete_char.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelisan </var/spool/mail/vladimir>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/20 07:10:58 by gmelisan          #+#    #+#             */
/*   Updated: 2019/07/30 05:49:57 by gmelisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "actions.h"

void	backward_delete_char(t_line *line)
{
	if (line->hs_mode)
	{
		if (line->hs.query.len > 0)
		{
			line->hs.query.s[line->hs.query.len - 1] = 0;
			line->hs.query.len -= 1;
			hs_find(line);
		}
		
	}
	else if (line->cpos > 0)
	{
		line->cpos--;
		str_remove(line->str, line->cpos, 1);		
	}
}
