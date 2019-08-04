/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history_search.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelisan <gmelisan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/28 16:51:21 by gmelisan          #+#    #+#             */
/*   Updated: 2019/07/30 20:16:03 by gmelisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "history_search.h"

static int	hs_strrstr(t_string haystack, t_string needle, int from)
{
	int	i;
	int	j;

	i = from;
	if (i < 0)
		return (-1);
	if (i > (int)haystack.len - 1)
		i = haystack.len - 1;
	while (str_get(haystack, i))
	{
		j = 0;
		while (str_get(haystack, i + j) == str_get(needle, j))
		{
			j++;
			if (!str_get(needle, j))
				return (i);
		}
		i--;
	}
	return (-1);
}

void	hs_prev(t_line *line)
{
	t_dlist *i;

	i = line->hs.hist_current;
	while (i->prev)
	{
		line->hs.query_pos = hs_strrstr(*(t_string *)i->content,
			line->hs.query, (i == line->hs.hist_current ?
								line->cpos - 1 : ((t_string *)i->content)->len));
		if (line->hs.query_pos >= 0)
		{
			line->hs.success = 1;
			line->str = (t_string *)i->content;
			line->history->item = i;
			line->hs.hist_current = i;
			return ;
		}
		i = i->prev;
	}
	line->hs.success = 0;
}


void	hs_find(t_line *line)
{
	t_dlist	*i;

	if (line->hs.query.len == 0)
	{
		line->history->item = line->hs.hist_start;
		line->str = (t_string *)line->history->item->content;
		line->cpos = line->hs.original_cpos;
		line->hs.query_pos = -1;
		return ;
	}
	i = line->hs.hist_current;
	while (i->prev)
	{
		line->hs.query_pos = hs_strrstr(*(t_string *)i->content,
			line->hs.query, (i == line->hs.hist_current ?
								line->cpos : ((t_string *)i->content)->len));
		if (line->hs.query_pos >= 0)
		{
			line->hs.success = 1;
			line->str = (t_string *)i->content;
			line->history->item = i;
			return ;
		}
		i = i->prev;
	}
	line->hs.success = 0;
}

static void	hs_decorate(t_line *line)
{
	int	i;
	int	j;

	i = -1;
	while (str_get(*line->str, ++i))
	{
		if (i == line->hs.query_pos)
		{
			line->cpos = i;
			j = 0;
			str_xinsert(line->str, i, UNDERLINE_SEQ, ft_strlen(UNDERLINE_SEQ));
			i += ft_strlen(UNDERLINE_SEQ);
			while (str_get(line->hs.query, ++j) ==
				   str_get(*line->str, ++i) && str_get(*line->str, i));
			str_xinsert(line->str, i, RESET_SEQ, ft_strlen(RESET_SEQ));
			break ;
		}
	}
}

void	hs_prepare_line(t_line *line)
{
	t_string	out_hs_string;

	line->hs.original_str = str_xduplicate(*line->str);
	hs_decorate(line);
	str_xaddback(line->str, "\n", 1);
	out_hs_string = str_xcopy(REVISRCH_STR);
	if (!line->hs.success)
		str_xaddfront(&out_hs_string, FAILSRCH_STR, ft_strlen(FAILSRCH_STR));
	str_xaddback(&out_hs_string, line->hs.query.s, line->hs.query.len);
	str_xaddback(&out_hs_string, "_", 1);
	str_xaddback(line->str, out_hs_string.s, ft_strlen(out_hs_string.s));
	str_delete(&out_hs_string);
}

void	hs_clear(t_line *line)
{
	/* int	nl; */

	/* nl = -1; */
	/* while (str_get(*line->str, ++nl)) */
	/* 	if (str_get(*line->str, nl) == '\n') */
	/* 		break; */
	/* if (str_get(*line->str, nl)) */
	/* { */
	/* 	ft_bzero(line->str->s + nl, line->str->len - nl); */
	/* 	line->str->len = nl; */
	/* } */
	str_delete(line->str);
	*line->str = line->hs.original_str;
}
