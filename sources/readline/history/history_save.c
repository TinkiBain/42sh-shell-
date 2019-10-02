/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history_save.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelisan <gmelisan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/28 20:12:19 by gmelisan          #+#    #+#             */
/*   Updated: 2019/10/02 16:43:19 by gmelisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_readline.h"

static void	history_save_rewrite(t_history *history)
{
	int		fd;
	t_dlist	*p;

	if ((fd = open(history->path, O_RDWR | O_TRUNC | O_CREAT, S_IRWXU)) < 0)
		return ;
	ft_dlst2start(&history->item);
	p = history->item;
	while (p)
	{
		ft_putendl_fd(((t_string *)p->content)->s, fd);
		p = p->next;
	}
	close(fd);
}

void		history_save(t_history *history)
{
	if (!history->path || !history->item)
		return ;
	history_save_rewrite(history);
	loginfo("History file '%s' has been updated", history->path);
}
