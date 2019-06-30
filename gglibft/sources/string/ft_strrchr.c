/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggwin-go <ggwin-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 18:24:43 by ggwin-go          #+#    #+#             */
/*   Updated: 2019/02/10 18:25:27 by ggwin-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*res;
	char	ch;
	size_t	len;

	len = ft_strlen(s);
	res = (char *)&s[len];
	ch = (char)c;
	while (res >= s)
	{
		if (*res == ch)
			return (res);
		res--;
	}
	return (NULL);
}
