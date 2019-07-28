/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelisan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 11:11:32 by gmelisan          #+#    #+#             */
/*   Updated: 2018/11/23 16:53:55 by gmelisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t len1;
	size_t len2;

	len1 = ft_strlen(dst);
	len2 = ft_strlen(src);
	if (size <= len1)
	{
		return (size + len2);
	}
	else
	{
		ft_strncat(dst, src, size - len1 - 1);
		return (len1 + len2);
	}
}
