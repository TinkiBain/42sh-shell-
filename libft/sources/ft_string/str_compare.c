/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_compare.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelisan <gmelisan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 22:16:04 by gmelisan          #+#    #+#             */
/*   Updated: 2019/03/12 08:14:28 by gmelisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

int			str_compare(t_string str1, t_string str2)
{
	int		minlen;
	int		i;
	char	c1;
	char	c2;

	minlen = (str1.len > str2.len ? str2.len : str1.len);
	i = 0;
	while (i < minlen + 1)
	{
		c1 = str_get(str1, i);
		c2 = str_get(str2, i);
		if (c1 != c2)
			return (c1 - c2);
	}
	return (0);
}
