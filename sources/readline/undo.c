/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   undo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wtalea <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/16 14:03:34 by wtalea            #+#    #+#             */
/*   Updated: 2019/08/16 14:44:51 by wtalea           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "undo.h"

t_undo_item	pop_undo_list(t_list **undo)
{
	t_undo_item		temp;
	t_list			*cp;

	cp = (*undo)->next;
	temp = *(t_undo_item *)((*undo)->content);
	free(*undo);
	*undo = cp;
	return (temp);
}

void		push_undo_list(t_string *str, int cpos, t_list **undo, int hstory)
{
	t_undo_item		new_undo;

	if (hstory)
		;
	new_undo.string = str_xduplicate(*str);
	new_undo.cpos = cpos;
	ft_lstadd(undo, (ft_lstnew(&new_undo, sizeof(t_undo_item))));
	if (!*undo)
		die();
}
