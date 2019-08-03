/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggwin-go <ggwin-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 16:30:42 by ggwin-go          #+#    #+#             */
/*   Updated: 2019/01/04 21:05:09 by ggwin-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*c_s;
	unsigned long	*l_s;

	l_s = (unsigned long *)s;
	while (n / (sizeof(long) * 5))
	{
		*(l_s++) = 0;
		*(l_s++) = 0;
		*(l_s++) = 0;
		*(l_s++) = 0;
		*(l_s++) = 0;
		n -= (sizeof(long) * 5);
	}
	while (n / sizeof(long))
	{
		*(l_s++) = 0;
		n -= sizeof(long);
	}
	c_s = (unsigned char *)l_s;
	while (n--)
		*(c_s++) = 0;
}
