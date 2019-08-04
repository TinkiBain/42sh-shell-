/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_split.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelisan <gmelisan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/01 18:07:00 by gmelisan          #+#    #+#             */
/*   Updated: 2019/03/12 18:36:32 by gmelisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

static int	count_len(t_string str, int (*isdelim)(int))
{
	int	len;
	int	i;

	len = 0;
	i = 0;
	while (str_get(str, i))
	{
		while (isdelim(str_get(str, i)))
			i++;
		if (!str_get(str, i))
			break ;
		while (str_get(str, i) && !isdelim(str_get(str, i)))
			i++;
		len++;
	}
	return (len);
}

t_string	*str_split(t_string str, int (*isdelim)(int))
{
	t_string	*res;
	int			i;
	int			j;

	res = (t_string *)ft_memalloc(sizeof(*res) *
									(count_len(str, isdelim) + 1));
	if (!res)
		return (NULL);
	i = 0;
	j = 0;
	while (str_get(str, i))
	{
		while (isdelim(str_get(str, i)))
			i++;
		if (!str_get(str, i))
			break ;
		while (str_get(str, i) && !isdelim(str_get(str, i)))
		{
			if (str_addback(&res[j], &str.s[i], 1) == NULL)
				return (NULL);
			i++;
		}
		j++;
	}
	return (res);
}
