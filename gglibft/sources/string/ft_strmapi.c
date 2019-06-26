/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggwin-go <ggwin-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 23:22:03 by ggwin-go          #+#    #+#             */
/*   Updated: 2019/02/10 18:24:41 by ggwin-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*str;
	char	*res;
	size_t	size;
	size_t	i;

	if (!s || !f)
		return (NULL);
	i = 0;
	size = ft_strlen((const char *)s);
	if (!(str = (char *)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	res = str;
	while (*s != '\0')
		*(str++) = f(i++, *(s++));
	*str = '\0';
	return (res);
}
