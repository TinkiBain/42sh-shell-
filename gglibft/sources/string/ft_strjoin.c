/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggwin-go <ggwin-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 23:55:49 by ggwin-go          #+#    #+#             */
/*   Updated: 2019/02/10 18:24:16 by ggwin-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	char	*res;
	size_t	size;
	size_t	i;
	size_t	j;

	if (!s1 || !s2)
		return (NULL);
	i = ft_strlen((const char *)s1);
	j = ft_strlen((const char *)s2);
	size = i + j;
	if ((size == (size_t)(-1)) || (size != (i + j)))
		return (NULL);
	if (!(str = (char *)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	res = str;
	while (*s1 != '\0')
		*(str++) = *(s1++);
	while (*s2 != '\0')
		*(str++) = *(s2++);
	*str = '\0';
	return (res);
}
