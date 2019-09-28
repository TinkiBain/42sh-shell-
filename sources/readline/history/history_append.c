/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history_append.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelisan <gmelisan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/21 18:37:50 by gmelisan          #+#    #+#             */
/*   Updated: 2019/09/28 20:23:32 by gmelisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "history.h"

static void	history_join_last(t_history *history, t_string *str)
{
	while (history->item->next)
		history->item = history->item->next;
	loginfo("Line \"%s\" has been joined to previous history line (\"%s\") "
			"and saved.", str->s, ((t_string *)history->item->content)->s);
	str_xaddback((t_string *)history->item->content, "\n", 1);
	str_xaddback((t_string *)history->item->content, str->s, str->len);
}

static void	push(t_history *history, t_string *str, int split_nl)
{
	char		**arr;
	int			i;
	t_string	newstr;

	if (ft_strchr(str->s, '\n') && split_nl)
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
	else
	{
		newstr = str_xduplicate(*str);
		history_push(history, newstr);
	}
}

void		history_append(t_history *history, t_string *str,
						 enum e_rl_mode mode, int split_nl)
{
	if (mode == RL_APPEND)
		history_join_last(history, str);
	else if (mode == RL_HEREDOC)
		return ;
	else if (str->len > 0)
	{
		push(history, str, split_nl);
		loginfo("Line \"%s\" has been pushed to history", str->s);
	}
}
