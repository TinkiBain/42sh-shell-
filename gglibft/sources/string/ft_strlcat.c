/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggwin-go <ggwin-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 21:03:29 by ggwin-go          #+#    #+#             */
/*   Updated: 2019/02/10 18:24:22 by ggwin-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	res;

	i = ft_strlen((const char *)dst);
	j = ft_strlen((const char *)src);
	if (size >= i)
	{
		res = i + j;
		dst += i;
		size -= i;
		while ((*src != '\0') && (--size))
			*(dst++) = *(src++);
		*dst = '\0';
	}
	else
		res = size + j;
	return (res);
}
