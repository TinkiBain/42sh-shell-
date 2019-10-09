/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history_expand.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggwin-go <ggwin-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/22 13:54:22 by gmelisan          #+#    #+#             */
/*   Updated: 2019/10/09 19:45:55 by gmelisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "history.h"

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
		if (c == '!')
		{
			if (first)
				move_cur_nl();
			if (!(res = history_expand_one(line, &i)))
				break ;
		}
		if (first)
			first = 0;
	}	
	return (res);
}
