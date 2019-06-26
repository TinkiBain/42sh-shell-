/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggwin-go <ggwin-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/30 01:36:31 by ggwin-go          #+#    #+#             */
/*   Updated: 2019/02/10 18:19:54 by ggwin-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_memcat(void *dst, const void *src, size_t start, size_t size)
{
	if (!dst || !src)
		return ;
	dst = &((unsigned char *)dst)[start];
	(void)ft_memmove(dst, src, size);
}
