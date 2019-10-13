/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backward_delete_char.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelisan <gmelisan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/20 07:10:58 by gmelisan          #+#    #+#             */
/*   Updated: 2019/10/14 01:55:35 by gmelisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "actions.h"

void	backward_delete_char(t_line *line)
{
	int i;

	i = -1;
	while (++i < line->arg)
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
			push_undo_list(line);
		}
}
