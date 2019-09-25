/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history_expand.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggwin-go <ggwin-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/22 13:54:22 by gmelisan          #+#    #+#             */
/*   Updated: 2019/09/25 22:26:33 by gmelisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "history.h"

static int		find_len(int n)
{
	int res;

	res = (n >= 0 ? 1 : 2);
	while ((n = n / 10))
		res++;
	return (res);
}

static t_string	*get_hist_n(t_history *history, int n, int *len)
{
	t_dlist *p;
	int		abs_n;
	int		i;

	abs_n = (n > 0 ? n : -n);
	*len = find_len(n);
	p = history->item;
	while (n > 0 ? p->prev : p->next)
		p = (n > 0 ? p->prev : p->next);
	i = (n > 0 ? history->start_index - 1 : -1);
	if ((n > 0 &&
		(n - history->start_index > history->size ||
		(n < history->start_index)))
		|| (n < 0 && (-n > history->size)))
		return (NULL);
	while (++i < abs_n && p)
		p = (n > 0 ? p->next : p->prev);
	if (p && p != history->item)
		return ((t_string *)p->content);
	return (NULL);
}

static t_string	*get_hist_str(t_history *history, char *s, int *len)
{
	t_dlist *p;

	*len = 0;
	while (!ft_isspace(s[*len]) && s[*len])
		*len += 1;
	if (*len == 0)
		return ((t_string *)history->item->content);
	p = history->item;
	while (p->next)
		p = p->next;
	while (p)
	{
		if (ft_strnequ(((t_string *)p->content)->s, s, *len))
			return ((t_string *)p->content);
		p = p->prev;
	}
	return (NULL);
}

static int		change_line(t_line *line, t_string *f, int i, int len)
{
	move_cur_nl();
	if (f)
	{
		loginfo("History expansion: %s -> %s", line->str->s, f->s);
		str_delete(&line->prompt);
		str_remove(line->str, i, len + 1);
		str_xinsert(line->str, i, f->s, f->len);
		return (1);
	}
	else
	{
		print_error("event not found", line->str->s);
		str_remove(line->str, 0, line->str->len);
		return (0);
	}
}

int				history_expand(t_line *line)
{
	int			i;
	char		c;
	t_string	*f;
	int			len;

	len = 0;
	i = 0;
	while (ft_isspace(str_get(*line->str, i)))
		i++;
	if (str_get(*line->str, i) == '!')
	{
		if (ft_isdigit((c = str_get(*line->str, i + 1))) || c == '-')
			f = get_hist_n(line->history, ft_atoi(line->str->s + i + 1), &len);
		else if (c == '!')
			f = get_hist_n(line->history, -1, &len);
		else
			f = get_hist_str(line->history, line->str->s + i + 1, &len);
		len = (c == '!' ? len - 1 : len);
		if (len == 0)
			return (1);
		return (change_line(line, f, i, len));
	}
	return (1);
}
