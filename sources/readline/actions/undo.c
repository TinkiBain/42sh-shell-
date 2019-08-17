/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   undo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wtalea <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/16 13:55:09 by wtalea            #+#    #+#             */
/*   Updated: 2019/08/17 19:03:04 by wtalea           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "actions.h"

void	undo(t_line *line)
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
			if ((undo = pop_undo_list(&line->undo)) == NULL)
				return ;
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
/*		temp = line->undo->next;
		if (line->undo)
		{
			del_undo_one(line->undo, 1);
			line->undo = temp;
		}*/
	}
}
