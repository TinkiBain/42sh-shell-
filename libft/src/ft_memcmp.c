/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelisan <gmelisan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 17:35:55 by gmelisan          #+#    #+#             */
/*   Updated: 2018/11/28 21:19:41 by gmelisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	i;
	t_uchar	ucs1;
	t_uchar	ucs2;

	i = 0;
	while (i < n)
	{
		ucs1 = *((t_uchar *)s1 + i);
		ucs2 = *((t_uchar *)s2 + i);
		if (ucs1 != ucs2)
			return (ucs1 - ucs2);
		i++;
	}
	return (0);
}
