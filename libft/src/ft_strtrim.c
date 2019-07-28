/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelisan <gmelisan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/25 20:47:50 by gmelisan          #+#    #+#             */
/*   Updated: 2018/11/27 17:24:23 by gmelisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strtrim(char const *s)
{
	size_t	len;
	size_t	from;
	size_t	to;
	char	*res;

	len = ft_strlen(s);
	if (len == 0)
		return ((char *)s);
	from = 0;
	while (s[from] == ' ' || s[from] == '\n' || s[from] == '\t')
		from++;
	if (s[from] == '\0')
	{
		res = (char *)malloc(sizeof(char) * 1);
		res[0] = '\0';
		return (res);
	}
	to = len - 1;
	while ((s[to] == ' ' || s[to] == '\n' || s[to] == '\t') && to != 0)
		to--;
	res = ft_strsub(s, from, to - from + 1);
	if (!res)
		return (NULL);
	return (res);
}
