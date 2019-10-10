/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history_expand_one.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelisan <gmelisan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 19:03:31 by gmelisan          #+#    #+#             */
/*   Updated: 2019/10/10 17:11:57 by gmelisan         ###   ########.fr       */
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
	int		i;

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
	while (++i < ft_abs(n) && p)
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
	if (f)
	{
		loginfo("History expansion: %s -> %s", line->str->s, f->s);
		str_delete(&line->prompt);
		str_remove(line->str, i, len + 1);
		str_xinsert(line->str, i, f->s, f->len);
		return (f->len);
	}
	else
	{
		print_error_vaarg("%.*s: event not found", len + 1, line->str->s + i);
		str_remove(line->str, 0, line->str->len);
		return (0);
	}
}

int				history_expand_one(t_line *line, int *pos, int *first)
{
	int			i;
	char		c;
	t_string	*f;
	int			len;

	len = 0;
	i = *pos;
	if (ft_isdigit((c = str_get(*line->str, i + 1))) || c == '-')
		f = get_hist_n(line->history, ft_atoi(line->str->s + i + 1), &len);
	else if (c == '!')
		f = get_hist_n(line->history, -1, &len);
	else
		f = get_hist_str(line->history, line->str->s + i + 1, &len);
	len = (c == '!' ? len - 1 : len);
	if (len == 0)
		return (1);
	if (*first)
		move_cur_nl();
	*first = 0;
	*pos += change_line(line, f, i, len) - 1;
	return (f ? f->len : 0);
}
