/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwisoky <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 15:47:28 by dwisoky           #+#    #+#             */
/*   Updated: 2019/09/27 16:45:14 by gmelisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int ch)
{
	char *str1;

	if (!str)
		return (NULL);
	str1 = (char *)str;
	while (*str1 != '\0')
	{
		if (*str1 == ch)
			return (str1);
		str1++;
	}
	if (*str1 == ch)
		return (str1);
	return (NULL);
}
