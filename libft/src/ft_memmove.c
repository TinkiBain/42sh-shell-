/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelisan <gmelisan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 15:39:38 by gmelisan          #+#    #+#             */
/*   Updated: 2019/03/04 13:25:35 by gmelisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memmove(void *dst, const void *src, size_t len)
{
	int		i;
	t_uchar	*cdst;
	t_uchar *csrc;

	cdst = (t_uchar *)dst;
	csrc = (t_uchar *)src;
	if (csrc < cdst)
	{
		i = len - 1;
		while (i >= 0)
		{
			cdst[i] = csrc[i];
			i--;
		}
	}
	else
		ft_memcpy(dst, src, len);
	return (dst);
}
