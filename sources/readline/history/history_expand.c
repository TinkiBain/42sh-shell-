/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history_expand.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelisan <gmelisan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/22 13:54:22 by gmelisan          #+#    #+#             */
/*   Updated: 2019/08/25 20:00:10 by gmelisan         ###   ########.fr       */
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
	i = history->start_index;
	if (n <= i)
		return (NULL);
	while (++i < (n > 0 ? n : -n) && p)
		p = (n > 0 ? p->next : p->prev);
	if (p)
		return ((t_string *)p->content);
	else
		return (NULL);
}

static t_string	*get_hist_str(t_history *history, char *s, int *len)
{
	t_dlist *p;

	*len = 0;
	while (!ft_isspace(s[*len]) && s[*len])
		*len += 1;
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

void			history_expand(t_line *line)
{
	int			i;
	char		c;
	t_string	*f;
	int			len;

	i = 0;
	while (ft_isspace(str_get(*line->str, i)))
		i++;
	if (str_get(*line->str, i) == '!')
	{
		if (ft_isdigit((c = str_get(*line->str, i + 1))) || c == '-')
			f = get_hist_n(line->history, ft_atoi(line->str->s + i + 1), &len);
		else if (c == '!')
		{
			f = get_hist_n(line->history, -1, &len);
			len--;
		}
		else
			f = get_hist_str(line->history, line->str->s + i + 1, &len);
		if (f)
		{
			str_remove(line->str, i, len + 1);
			str_xinsert(line->str, i, f->s, f->len);
		}
	}
}
