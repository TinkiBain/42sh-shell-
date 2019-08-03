/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggwin-go <ggwin-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/25 14:53:56 by ggwin-go          #+#    #+#             */
/*   Updated: 2019/02/13 14:55:09 by ggwin-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	unsigned char	*s;

	s = NULL;
	if (size == 0)
		return (NULL);
	s = (unsigned char *)malloc(sizeof(unsigned char) * size);
	if (s == NULL)
		return (NULL);
	ft_bzero(s, size);
	return ((void *)s);
}
