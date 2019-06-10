/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggwin-go <ggwin-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 17:37:20 by ggwin-go          #+#    #+#             */
/*   Updated: 2019/01/04 19:02:31 by ggwin-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*c_dst;
	unsigned char	*c_src;
	unsigned long	*l_dst;
	unsigned long	*l_src;

	if (dst == src || n == 0)
		return (dst);
	l_dst = (unsigned long *)dst;
	l_src = (unsigned long *)src;
	while (n / (sizeof(long) * 2))
	{
		*(l_dst++) = *(l_src++);
		*(l_dst++) = *(l_src++);
		n -= (sizeof(long) * 2);
	}
	while (n / sizeof(long))
	{
		*(l_dst++) = *(l_src++);
		n -= sizeof(long);
	}
	c_dst = (unsigned char *)l_dst;
	c_src = (unsigned char *)l_src;
	while (n--)
		*(c_dst++) = *(c_src++);
	return (dst);
}
