/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reset_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelisan <gmelisan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/30 16:37:41 by gmelisan          #+#    #+#             */
/*   Updated: 2019/08/07 05:01:34 by gmelisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "actions.h"

void	reset_line(t_line *line)
{
	while (line->history->item->next)
		line->history->item = line->history->item->next;
	line->str = (t_string *)line->history->item->content;
	str_delete(line->str);
	*line->str = str_xcreate(0);
	line->cpos = 0;
	line->hs_mode = 0;
	line->reading_arg = 0;
	line->arg = 1;
	if (line->vi_mode)
		line->vi_mode = VI_INSERT;
	update_bindings(line->vi_mode, &line->key_bindings);
	clear_linebuf();
	init_linebuf(line);
	ft_putstr("\n");
}
