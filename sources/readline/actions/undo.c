/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   undo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wtalea <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/16 13:55:09 by wtalea            #+#    #+#             */
/*   Updated: 2019/08/16 16:23:17 by wtalea           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "actions.h"

void	undo(t_line *line)
{
	t_undo_item		undo;
	t_string		*cp;

	cp = line->str;
	undo = pop_undo_list(&line->undo);
	ft_bzero(line->str->s, line->str->len);
	line->str->len = 0;
	str_xaddback(line->str, undo.string.s, undo.string.len);
	line->cpos = undo.cpos;
}
