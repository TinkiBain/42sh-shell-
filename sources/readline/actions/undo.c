/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   undo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wtalea <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/16 13:55:09 by wtalea            #+#    #+#             */
/*   Updated: 2019/08/24 15:46:09 by wtalea           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "actions.h"

static	void	undo_del(t_line *line, t_undo_item **undo)
{
	ft_bzero(line->str->s, line->str->len);
	line->str->len = 0;
	str_xaddback(line->str, (*undo)->string.s, (*undo)->string.len);
	line->cpos = (*undo)->cpos;
	if (*undo)
	{
		str_delete(&(*undo)->string);
		free(*undo);
	}
}

static	void	undo_else(t_line *line)
{
	ft_bzero(line->str->s, line->str->len);
	line->str->len = 0;
	str_xaddback(line->str, "", 0);
	line->cpos = 0;
}

static	void	undo_go_history(t_line *line, int lenh)
{
	while (next_history_check(line))
		;
	while (lenh--)
		previous_history_check(line);
}

static	void	undo_zero(t_line *line)
{
	ft_bzero(line->str->s, line->str->len);
	line->str->len = 0;
	str_xaddback(line->str, "", 0);
	line->cpos = 0;
}

void			undo(t_line *line)
{
	t_undo_item		*undo;
	t_string		*cp;
	t_list			*temp;

	temp = NULL;
	undo = NULL;
	cp = line->str;
	if ((undo = pop_undo_list(&line->undo)) != NULL)
	{
		undo_go_history(line, undo->lenh);
		if (!ft_strcmp(line->str->s, undo->string.s))
		{
			str_delete(&undo->string);
			undo ? free(undo) : 1;
			if ((undo = pop_undo_list(&line->undo)) == NULL)
			{
				undo_zero(line);
				return ;
			}
			undo_go_history(line, undo->lenh);
		}
		undo_del(line, &undo);
	}
	else
		undo_else(line);
}
