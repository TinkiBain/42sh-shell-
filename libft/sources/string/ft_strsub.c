/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggwin-go <ggwin-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 23:42:29 by ggwin-go          #+#    #+#             */
/*   Updated: 2019/01/04 23:23:59 by ggwin-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*str;
	char	*res;

	if (!s || (len == (size_t)(-1)))
		return (NULL);
	str = (char *)malloc(sizeof(char) * (len + 1));
	res = str;
	if (!str)
		return (NULL);
	s = &s[start];
	while (len--)
		*(str++) = *(s++);
	*str = '\0';
	return (res);
}
