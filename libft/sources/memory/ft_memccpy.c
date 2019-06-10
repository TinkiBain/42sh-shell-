/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggwin-go <ggwin-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 18:58:31 by ggwin-go          #+#    #+#             */
/*   Updated: 2019/01/04 21:33:11 by ggwin-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*c_dst;
	unsigned char	*c_src;
	unsigned char	ch;

	ch = (unsigned char)c;
	c_dst = (unsigned char *)dst;
	c_src = (unsigned char *)src;
	if (n == 0)
		return (NULL);
	while (n--)
	{
		*c_dst = *c_src;
		if (*c_src == ch)
			return (++c_dst);
		c_dst++;
		c_src++;
	}
	return (NULL);
}
