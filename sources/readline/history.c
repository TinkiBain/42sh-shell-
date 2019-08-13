/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelisan </var/spool/mail/vladimir>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/16 21:18:46 by gmelisan          #+#    #+#             */
/*   Updated: 2019/08/13 08:37:17 by gmelisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_readline.h"

static void	del(void *content, size_t size)
{
	if (size || !size)
		str_delete((t_string *)content);
	free(content);
}

t_history	*history_copy(t_history *history)
{
	t_history	*newhist;
	t_string	str;

	newhist = ft_xmemalloc(sizeof(*newhist));
	if (history->size == 0)
		return (newhist);
	while (history->item->prev)
		history->item = history->item->prev;
	while (history->item->next)
	{
		str = str_xduplicate(*((t_string *)history->item->content));
		history_push(newhist, str);
		history->item = history->item->next;
	}
	str = str_xduplicate(*((t_string *)history->item->content));
	history_push(newhist, str);
	return (newhist);
}

int			history_open(t_history *history, char *path)
{
	int		fd;

	fd = -1;
	history->path = convert_tilde(path);
	if (history->path)
		fd = open(history->path, O_RDONLY | O_CREAT, S_IRWXU);
	if (fd < 0)
		loginfo("Can't open history file");
	else
		loginfo("History location: %s", history->path);
	return (fd);
}

void		history_load(t_history *history, char *path)
{
	int			fd;
	t_string	str;
	int			ret;

	if (!path)
		return ;
	if ((fd = history_open(history, path)) < 0)
		return ;
	while ((ret = get_next_line(fd, &str.s)) > 0)
	{
		str_fixlen(&str);
		ft_dlstaddback(&history->item, ft_dlstnew(&str, sizeof(str)));
		history->size++;
	}
	if (ret < 0)
		loginfo("Error in history get_next_line()");
	while (history->size > HISTORY_MAXSIZE)
	{
		ft_dlstdelfront(&history->item, del);
		history->size--;
	}
	close(fd);
}

void		history_clear(t_history *history)
{
	if (history)
	{
		ft_dlstdel(&history->item, del);
		ft_strdel(&history->path);
		free(history);
	}
}

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
	if (history->size >= HISTORY_MAXSIZE)
		history_save_rewrite(history);
	else
		history_save_append(history);
}

void		history_push(t_history *history, t_string str)
{
	t_dlist *new;

	if (history->size >= HISTORY_MAXSIZE)
	{
		ft_dlstdelfront(&history->item, del);
		history->size--;
	}
	new = ft_dlstnew(&str, sizeof(str));
	ft_dlstaddback(&history->item, new);
	history->size++;
}
