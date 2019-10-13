/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   undo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelisan <gmelisan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/16 14:03:34 by gmelisan          #+#    #+#             */
/*   Updated: 2019/10/14 01:56:14 by gmelisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "undo.h"
#include "del_funcs.h"

t_undo_item		*pop_undo_list(t_list **undo)
{
	t_undo_item		*temp;
	t_list			*cp;

	cp = NULL;
	temp = NULL;
	if (*undo && ((*undo)->next))
	{
		cp = (*undo)->next;
		temp = (t_undo_item *)xmalloc(sizeof(t_undo_item));
		*temp = *(t_undo_item *)((*undo)->content);
		del_undo_one(*undo, 1);
		*undo = cp;
	}
	else if (!((*undo)->next))
		return (NULL);
	return (temp);
}

void			push_undo_list(t_line *line)
{
	t_undo_item		new_undo;
	int				len;

	if (!(line->undo) || ((line->undo) && ft_strcmp(line->str->s, ((t_undo_item
							*)(line->undo)->content)->string.s)))
	{
		len = 0;
		new_undo.string = str_xduplicate(*line->str);
		new_undo.cpos = line->cpos;
		new_undo.lenh = len_history(line);
		ft_lstadd(&line->undo, (ft_lstnew(&new_undo, sizeof(t_undo_item))));
		if (!*undo)
			die();
	}
}
