/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vi_paste_after.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelisan <gmelisan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/16 03:46:52 by gmelisan          #+#    #+#             */
/*   Updated: 2019/08/25 19:27:54 by gmelisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "actions.h"

void	vi_paste_after(t_line *line)
{
	int i;

	if (line->kill_buffer.len > 0)
	{
		i = -1;
		while (++i < line->arg)
		{
			str_xinsert(line->str, line->cpos + 1,
						line->kill_buffer.s, line->kill_buffer.len);
			line->cpos += line->kill_buffer.len;
		}
	}
}
