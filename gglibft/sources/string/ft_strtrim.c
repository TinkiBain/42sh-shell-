/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggwin-go <ggwin-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 16:53:41 by ggwin-go          #+#    #+#             */
/*   Updated: 2019/02/10 18:25:46 by ggwin-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char	*str;
	char	*res;
	char	c;
	size_t	i;
	size_t	size;

	if (!s)
		return (NULL);
	while (*s != '\0' && (*s == ' ' || *s == '\t' || *s == '\n'))
		s++;
	size = ft_strlen((char *)s);
	size = (size == 0) ? 0 : size - 1;
	i = 0;
	while ((size - i) && ((c = s[size - i]) == ' ' || c == '\t'
			|| c == '\n'))
		i++;
	if (!(str = (char *)malloc(sizeof(char) * (size - i + 2))))
		return (NULL);
	res = str;
	while (*s != '\0' && ((size--) - i + 1) > 0)
		*(str++) = *(s++);
	*str = '\0';
	return (res);
}
