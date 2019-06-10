/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggwin-go <ggwin-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 15:32:33 by ggwin-go          #+#    #+#             */
/*   Updated: 2019/02/10 18:25:07 by ggwin-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	char *res;

	res = dst;
	if (len == 0)
		return (dst);
	while (len && *src != '\0')
	{
		*dst++ = *src++;
		len--;
	}
	ft_bzero(dst, len);
	return (res);
}
