/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelisan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 15:26:17 by gmelisan          #+#    #+#             */
/*   Updated: 2018/11/22 16:17:50 by gmelisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strcmp(const char *s1, const char *s2)
{
	size_t	i;
	t_uchar	ucs1;
	t_uchar	ucs2;

	i = 0;
	while (s1[i])
	{
		ucs1 = *((t_uchar *)s1 + i);
		ucs2 = *((t_uchar *)s2 + i);
		if (ucs1 != ucs2)
			return (ucs1 - ucs2);
		i++;
	}
	ucs1 = *((t_uchar *)s1 + i);
	ucs2 = *((t_uchar *)s2 + i);
	if (ucs1 != ucs2)
		return (ucs1 - ucs2);
	return (0);
}
