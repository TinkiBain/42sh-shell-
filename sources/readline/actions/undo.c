/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   undo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wtalea <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/16 13:55:09 by wtalea            #+#    #+#             */
/*   Updated: 2019/08/23 18:25:08 by wtalea           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "actions.h"

int		undo(t_line *line)
{
	t_undo_item		*undo;
	t_string		*cp;
	int				i;
	t_list			*temp;

	temp = NULL;
	undo = NULL;
	i = 0;
	cp = line->str;
	if ((undo = pop_undo_list(&line->undo)) != NULL && *undo->string.s)
	{
		i = undo->lenh;
		while (next_history_check(line))
			;
		while (i--)
			previous_history_check(line);
		if (!ft_strcmp(line->str->s, undo->string.s))
		{
			undo ? free(undo) : 1;
			if ((undo = pop_undo_list(&line->undo)) == NULL)
				return (0);
			i = undo->lenh;
			while (next_history_check(line))
				;
			while (i--)
				previous_history_check(line);
		}
		ft_bzero(line->str->s, line->str->len);
		line->str->len = 0;
		str_xaddback(line->str, undo->string.s, undo->string.len);
		line->cpos = undo->cpos;
		if (undo)
			free(undo);
		if (line->undo && line->undo->next)
		{
			temp = line->undo->next;
			del_undo_one(line->undo, 1);
			line->undo = temp;
		}
		if (line->undo->next)
			return (1);
		return (0);
	}
	return (0);
}
