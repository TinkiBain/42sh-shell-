/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggwin-go <ggwin-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 17:01:45 by ggwin-go          #+#    #+#             */
/*   Updated: 2019/01/04 23:10:48 by ggwin-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strchr(const char *s, int c)
{
	char	*s1;
	char	ch;

	s1 = (char *)s;
	ch = (char)c;
	while (*s1 != '\0')
	{
		if (*s1 == ch)
			return (s1);
		s1++;
	}
	return ((*s1 == ch) ? (s1) : (NULL));
}
