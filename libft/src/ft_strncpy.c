/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelisan <gmelisan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 20:41:45 by gmelisan          #+#    #+#             */
/*   Updated: 2018/11/22 11:23:52 by gmelisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	size_t i;
	size_t src_len;

	i = 0;
	src_len = ft_strlen(src);
	if (len <= src_len)
		ft_memcpy(dst, src, len);
	else
	{
		ft_memcpy(dst, src, src_len);
		i = src_len;
		while (i < len)
		{
			dst[i] = '\0';
			i++;
		}
	}
	return (dst);
}
