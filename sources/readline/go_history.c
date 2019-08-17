/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   go_history.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wtalea <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/16 17:21:21 by wtalea            #+#    #+#             */
/*   Updated: 2019/08/17 18:25:16 by wtalea           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "go_history.h"

int				next_history_check(t_line *line)
{
	if (line->history->item->next)
	{
		line->history->item = line->history->item->next;
		line->str = (t_string *)line->history->item->content;
		line->cpos = line->str->len;
		return (1);
	}
	return (0);
}

int				previous_history_check(t_line *line)
{
	if (line->history->item->prev)
	{
		line->history->item = line->history->item->prev;
		line->str = (t_string *)line->history->item->content;
		line->cpos = line->str->len;
		return (1);
	}
	return (0);
}

int				len_history(t_line *line)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (next_history_check(line))
		++i;
	j = i;
	while (j--)
		previous_history_check(line);
	return (i);
}

