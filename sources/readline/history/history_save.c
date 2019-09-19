/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history_save.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelisan <gmelisan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/21 18:37:50 by gmelisan          #+#    #+#             */
/*   Updated: 2019/09/19 18:05:53 by gmelisan         ###   ########.fr       */
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

static void	history_join_last(t_history *history, t_string *str)
{
	while (history->item->next)
		history->item = history->item->next;
	loginfo("Line \"%s\" has been joined to previous history line (\"%s\") "
			"and saved.", str->s, ((t_string *)history->item->content)->s);
	str_xaddback((t_string *)history->item->content, "\n", 1);
	str_xaddback((t_string *)history->item->content, str->s, str->len);
	history_save_rewrite(history);
}

static void	push(t_history *history, t_string *str)
{
	char		**arr;
	int			i;
	t_string	newstr;

	if (!ft_strchr(str->s, '\n'))
	{
		newstr = str_xduplicate(*str);
		history_push(history, newstr);
	}
	else
	{
		arr = ft_xstrsplit(str->s, '\n');
		i = -1;
		while (arr[++i])
		{
			newstr = str_xcopy(arr[i]);
			history_push(history, newstr);
		}
		ft_free_double_ptr_arr((void ***)&arr);
	}
}

void		history_save(t_history *history, t_string *str, enum e_rl_mode mode)
{
	if (mode == RL_APPEND)
		history_join_last(history, str);
	else if (mode == RL_HEREDOC)
		return ;
	else if (str->len > 0)
	{
		push(history, str);
		if (!history->path)
			return ;
		if (history->size >= history->max_size)
			history_save_rewrite(history);
		else
			history_save_append(history);
		loginfo("Line \"%s\" has been pushed to history", str->s);
	}
}
