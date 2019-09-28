/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history_save.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelisan <gmelisan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/28 20:12:19 by gmelisan          #+#    #+#             */
/*   Updated: 2019/09/28 20:26:59 by gmelisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_readline.h"

static void	history_save_rewrite(t_history *history)
{
	int fd;

	if ((fd = open(history->path, O_RDWR | O_TRUNC | O_CREAT, S_IRWXU)) < 0)
		return ;
	while (history->item->prev)
		history->item = history->item->prev;
	if (history->item->next)
	{
		history->item = history->item->next;
		while (history->item->next)
		{
			ft_putendl_fd(((t_string *)history->item->content)->s, fd);
			history->item = history->item->next;
		}
	}
	ft_putendl_fd(((t_string *)history->item->content)->s, fd);
	close(fd);
}

void		history_save(t_history *history)
{
	if (!history->path || !history->item)
		return ;
	history_save_rewrite(history);
	loginfo("History file '%s' has been updated", history->path);
}
