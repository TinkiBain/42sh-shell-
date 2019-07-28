/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelisan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 17:59:20 by gmelisan          #+#    #+#             */
/*   Updated: 2018/11/22 17:33:50 by gmelisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t	i;
	t_uchar	u_c;

	u_c = (t_uchar)c;
	i = 0;
	while (i < n)
	{
		if (*((t_uchar *)src + i) == u_c)
		{
			*((t_uchar *)dst + i) = *((t_uchar *)src + i);
			i++;
			return ((t_uchar *)dst + i);
		}
		*((t_uchar *)dst + i) = *((t_uchar *)src + i);
		i++;
	}
	return (NULL);
}
