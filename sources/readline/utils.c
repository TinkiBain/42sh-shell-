/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelisan <gmelisan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/07 21:16:01 by gmelisan          #+#    #+#             */
/*   Updated: 2019/10/13 12:36:09 by gmelisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int			max_int(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

int			cmp_pstring(const void *a, const void *b)
{
	return (ft_strcmp(((t_string *)a)->s,
						((t_string *)b)->s));
}

void		convert_escapes(t_string *str)
{
	int		i;
	char	c;
	t_uchar	n;
	int		count;

	i = -1;
	n = 0;
	while ((c = str_get(*str, ++i)))
	{
		if (c == '\\')
			n = ft_atoi_octal(&str->s[i + 1], &count);
		if (n)
		{
			str_remove(str, i, count + 1);
			str_xinsert(str, i, (char *)&n, 1);
		}
		n = 0;
	}
}
