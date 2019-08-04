/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelisan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 19:47:32 by gmelisan          #+#    #+#             */
/*   Updated: 2019/03/11 03:34:58 by gmelisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*
** Returns index of \n, or index of first 0 after non-0.
** If not found, returns BUFF_SIZE.
*/

static int	find_endl(char *buf)
{
	int i;
	int not_endlzero;

	i = 0;
	not_endlzero = 0;
	while (i < BUFF_SIZE)
	{
		if (buf[i] && buf[i] != '\n')
			not_endlzero = 1;
		if (not_endlzero && !buf[i])
			return (i);
		if (buf[i] == '\n')
			return (i);
		i++;
	}
	return (i);
}

/*
** Reads line from fd, and append it to 'line'.
** Loops while \n or EOF encounters. Chars after EOF become 0.
** Chars before \n inclusive become 0.
*/

static int	save_next_line(char *buf, const int fd, char **line)
{
	int		ret;
	int		endl;
	int		read_flag;

	read_flag = 0;
	while ((ret = read(fd, buf, BUFF_SIZE)))
	{
		if (ret == -1)
			return (-1);
		endl = find_endl(buf);
		if (ret < BUFF_SIZE)
			ft_bzero(buf + ret, BUFF_SIZE - ret);
		ft_realloc(
			(void **)line, ft_strlen(*line), ft_strlen(*line) + endl + 1);
		ft_memcpy(*line + ft_strlen(*line), buf, endl);
		read_flag = 1;
		if (endl < BUFF_SIZE)
		{
			ft_bzero(buf, endl + 1);
			return (read_flag);
		}
	}
	ft_bzero(buf, BUFF_SIZE);
	return (read_flag);
}

/*
** Main control functions. Skips first 0 in buffer, gets line from first non-0
** to result of find_endl(). If endl < BUFF_SIZE, zeroes got part and returns.
** Else, invokes save_next_line to append line from fd.
** Condition "if (ret == 0 && start != BUFF_SIZE)" is for case when
** we have buffer [abc] and next read is EOF (0).
*/

static int	handle_buf(char *buf, const int fd, char **line)
{
	int		endl;
	int		ret;
	int		start;

	if (!line)
		return (-1);
	start = 0;
	while (!buf[start] && start != BUFF_SIZE)
		start++;
	endl = find_endl(buf);
	*line = ft_strsub(buf, start, endl - start);
	if (endl < BUFF_SIZE)
	{
		ft_bzero(buf, endl + 1);
		return (1);
	}
	ret = save_next_line(buf, fd, line);
	if (ret == 0 && start != BUFF_SIZE)
		return (1);
	if (ret != 1)
		ft_strdel(line);
	return (ret);
}

/*
** Finds item in list and removes, keeping linking valid.
*/

static void	ft_lstremove(t_list **list, t_list *item)
{
	t_list	*i;
	t_list	*prev;

	i = *list;
	prev = NULL;
	if (i == item)
	{
		*list = (*list)->next;
		free(i->content);
		free(i);
		return ;
	}
	while (i)
	{
		if (i == item)
		{
			prev->next = i->next;
			free(i->content);
			free(i);
			return ;
		}
		prev = i;
		i = i->next;
	}
}

/*
** Reads one line from fd. Line is a succession of characters until '\n'
** or EOF. Returns 1 on success, 0 if EOF and -1 in case of error.
*/

int			get_next_line(const int fd, char **line)
{
	static t_list	*buflist;
	t_gnlbuf		*gnlbuf;
	t_list			*i;
	int				ret;

	i = buflist;
	while (i)
	{
		gnlbuf = (t_gnlbuf *)i->content;
		if (gnlbuf->fd == fd)
		{
			if (!(ret = handle_buf(gnlbuf->buf, gnlbuf->fd, line)))
				ft_lstremove(&buflist, i);
			return (ret);
		}
		i = i->next;
	}
	gnlbuf = ft_memalloc(sizeof(*gnlbuf));
	gnlbuf->fd = fd;
	ft_lstadd(&buflist, ft_lstnew(NULL, 0));
	buflist->content = gnlbuf;
	if (!(ret = handle_buf(gnlbuf->buf, gnlbuf->fd, line)))
		ft_lstremove(&buflist, i ? i : buflist);
	return (ret);
}
