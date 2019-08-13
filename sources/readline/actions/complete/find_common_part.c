/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_common_part.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelisan </var/spool/mail/vladimir>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/13 07:27:42 by gmelisan          #+#    #+#             */
/*   Updated: 2019/08/13 07:28:09 by gmelisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "actions.h"

static int		get_min_len(t_vector vec)
{
	int			i;
	t_string	*str;
	t_uint		min;

	min = (t_uint)-1;
	i = -1;
	while (++i < (int)vec.len)
	{
		str = vec_get(vec, i);
		if (str->len < min)
			min = str->len;
	}
	return ((int)min);
}

t_string	find_common_part(t_vector vec)
{
	t_string	res;
	int			i;
	int			j;
	int			min;
	char		prev;

	res = str_create(0);
	min = get_min_len(vec);
	i = -1;
	while (++i < min)
	{
		j = 0;
		prev = str_get(*(t_string *)vec_get(vec, j), i);
		while (++j < (int)vec.len)
		{
			if (str_get(*(t_string *)vec_get(vec, j), i) != prev)
				return (res);
		}
		str_xaddback(&res, &prev, 1);
	}
	return (res);
}
