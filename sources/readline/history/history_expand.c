/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history_expand.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggwin-go <ggwin-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/22 13:54:22 by gmelisan          #+#    #+#             */
/*   Updated: 2019/10/10 17:18:09 by gmelisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "history.h"

static void		skip(t_line *line, int *i)
{
	char	c;

	while ((c = str_get(*line->str, *i)))
	{
		if (c == ']')
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
		if (c == '[')
			skip(line, &i);
		else if (c == '!' &&
				!(res = history_expand_one(line, &i, &first)))
			break ;
	}	
	return (res);
}
