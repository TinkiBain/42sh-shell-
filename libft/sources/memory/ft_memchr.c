/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggwin-go <ggwin-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 22:04:20 by ggwin-go          #+#    #+#             */
/*   Updated: 2019/01/04 21:30:53 by ggwin-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*c_s;
	unsigned char	ch;

	ch = (unsigned char)c;
	c_s = (unsigned char *)s;
	while (n--)
	{
		if (*c_s == ch)
			return ((void *)c_s);
		c_s++;
	}
	return (NULL);
}
