/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   undo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wtalea <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/16 14:03:34 by wtalea            #+#    #+#             */
/*   Updated: 2019/08/16 18:39:50 by wtalea           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "undo.h"
#include "go_history.h"

t_undo_item		*pop_undo_list(t_list **undo)
{
	t_undo_item		*temp;
	t_list			*cp;

	cp = NULL;
	temp = NULL;
	if (*undo)
	{
		cp = (*undo)->next;
		(temp = (t_undo_item *)malloc(sizeof(t_undo_item))) ? 1 : die();
		*temp = *(t_undo_item *)((*undo)->content);
		free(*undo);
		*undo = cp;
	}
	return (temp);
}

void			push_undo_list(t_string *str, int cpos, t_list **undo,
		t_line *line)
{
	t_undo_item		new_undo;
	int				len;

	len = 0;
	new_undo.string = str_xduplicate(*str);
	new_undo.cpos = cpos;
	new_undo.lenh = len_history(line);
	ft_lstadd(undo, (ft_lstnew(&new_undo, sizeof(t_undo_item))));
	if (!*undo)
		die();
}

void			del_undo_one(void *p, size_t i)
{
	if (i)
		;
	if (p)
		str_delete(&((t_undo_item *)p)->string);
	free(p);
}
