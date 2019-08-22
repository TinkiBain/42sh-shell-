/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history_save.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelisan </var/spool/mail/vladimir>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/21 18:37:50 by gmelisan          #+#    #+#             */
/*   Updated: 2019/08/21 18:37:58 by gmelisan         ###   ########.fr       */
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
			ft_fdprintf(fd, "%s\n", ((t_string *)history->item->content)->s);
			history->item = history->item->next;
		}
	}
	ft_fdprintf(fd, "%s\n", ((t_string *)history->item->content)->s);
	close(fd);
}

static void	history_save_append(t_history *history)
{
	int fd;

	if ((fd = open(history->path, O_RDWR | O_APPEND | O_CREAT, S_IRWXU)) < 0)
		return ;
	while (history->item->next)
			history->item = history->item->next;
	ft_fdprintf(fd, "%s\n", ((t_string *)history->item->content)->s);
	close(fd);
}

void	history_save(t_history *history, t_string *str)
{
	t_string	newstr;

	if (str->len == 0)
		return ;
	newstr = str_xduplicate(*str);
	history_push(history, newstr);
	if (!history->path)
		return ;
	if (history->size >= history->max_size)
		history_save_rewrite(history);
	else
		history_save_append(history);
}
