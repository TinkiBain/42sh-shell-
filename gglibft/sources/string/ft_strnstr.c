/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggwin-go <ggwin-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 19:47:06 by ggwin-go          #+#    #+#             */
/*   Updated: 2018/12/30 19:05:19 by ggwin-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	const char	*h;
	const char	*n;
	size_t		l;

	if (*needle == '\0' || haystack == needle)
		return ((char *)haystack);
	while (len && *haystack != '\0')
	{
		if (*haystack == *needle)
		{
			h = haystack;
			n = needle;
			l = len;
			while (*h != '\0' && *n != '\0' && *(h++) == *n && (l-- + 1))
				n++;
			if (*n == '\0')
				return ((char *)haystack);
		}
		haystack++;
		len--;
	}
	return (NULL);
}
