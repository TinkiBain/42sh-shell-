/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_common_part.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelisan <gmelisan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/13 07:27:42 by gmelisan          #+#    #+#             */
/*   Updated: 2019/09/05 21:39:53 by gmelisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "actions.h"

static t_uint	get_min_len(char **arr, int n)
{
	int			i;
	t_uint		len;
	t_uint		min;

	min = (t_uint)-1;
	i = -1;
	while (++i < n)
	{
		len = ft_strlen(arr[i]);
		if (len < min)
			min = len;
	}
	return (min);
}

t_string		find_common_part(char **arr, int n)
{
	t_string	res;
	int			i;
	int			j;
	int			min;
	char		prev;

	res = str_create(0);
	if (arr == NULL)
		return (res);
	min = get_min_len(arr, n);
	i = -1;
	while (++i < min)
	{
		j = 0;
		prev = arr[j][i];
		while (++j < n)
		{
			if (arr[j][i] != prev)
				return (res);
		}
		str_xaddback(&res, &prev, 1);
	}
	return (res);
}
