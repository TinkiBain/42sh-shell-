/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy_rev.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggwin-go <ggwin-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/30 01:47:04 by ggwin-go          #+#    #+#             */
/*   Updated: 2018/12/31 21:46:16 by ggwin-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memcpy_rev(void *dst, const void *src, size_t n)
{
	unsigned char	*c_dst;
	unsigned char	*c_src;
	unsigned long	*l_dst;
	unsigned long	*l_src;

	if (dst == src || n == 0)
		return (dst);
	l_dst = (unsigned long *)&(((unsigned char *)dst)[n]);
	l_src = (unsigned long *)&(((unsigned char *)src)[n]);
	while (n / (sizeof(long) * 2))
	{
		*(--l_dst) = *(--l_src);
		*(--l_dst) = *(--l_src);
		n -= (sizeof(long) * 2);
	}
	while (n >= sizeof(long))
	{
		*(--l_dst) = *(--l_src);
		n -= sizeof(long);
	}
	c_dst = (unsigned char *)l_dst;
	c_src = (unsigned char *)l_src;
	while (n--)
		*(--c_dst) = *(--c_src);
	return (dst);
}
