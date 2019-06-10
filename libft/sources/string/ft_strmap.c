/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggwin-go <ggwin-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 23:02:18 by ggwin-go          #+#    #+#             */
/*   Updated: 2019/02/10 18:24:36 by ggwin-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*str;
	char	*res;
	size_t	size;

	if (!s || !f)
		return (NULL);
	size = ft_strlen((const char *)s);
	if (!(str = (char *)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	res = str;
	while (*s != '\0')
		*(str++) = f(*(s++));
	*str = '\0';
	return (res);
}
