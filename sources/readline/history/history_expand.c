/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history_expand.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelisan <gmelisan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/22 13:54:22 by gmelisan          #+#    #+#             */
/*   Updated: 2019/11/01 19:57:15 by gmelisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "history.h"

static char		get_stop(char c)
{
	if (c == '[')
		return (']');
	if (c == '(')
		return (')');
	if (c == '\'')
		return (c);
	if (c == '"')
		return (c);
	return (0);
}

static void		skip(t_line *line, int *i)
{
	char	c;
	char	stop;

	stop = get_stop(str_get(*line->str, *i));
	*i += 1;
	while ((c = str_get(*line->str, *i)))
	{
		if (c == stop)
			break ;
		*i += 1;
	}
}

int				history_expand(t_line *line)
{
	int		i;
	char	c;
	int		res;
	int		first;

	res = 1;
	i = -1;
	first = 1;
	while ((c = str_get(*line->str, ++i)))
	{
		if (ft_strchr("[('\"", c))
			skip(line, &i);
		else if (c == '!' &&
				!(res = history_expand_one(line, &i, &first)))
			break ;
	}
	return (res);
}
