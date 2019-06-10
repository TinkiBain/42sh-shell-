/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggwin-go <ggwin-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 19:13:52 by ggwin-go          #+#    #+#             */
/*   Updated: 2019/01/04 23:01:54 by ggwin-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strstr(const char *haystack, const char *needle)
{
	const char	*h;
	const char	*n;

	if (*needle == '\0' || haystack == needle)
		return ((char *)haystack);
	while (*haystack != '\0')
	{
		if (*haystack == *needle)
		{
			h = haystack;
			n = needle;
			while (*h != '\0' && *n != '\0' && *(h++) == *n)
				n++;
			if (*n == '\0')
				return ((char *)haystack);
		}
		haystack++;
	}
	return (NULL);
}
