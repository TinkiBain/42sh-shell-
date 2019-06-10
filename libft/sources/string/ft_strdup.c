/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggwin-go <ggwin-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 19:13:11 by ggwin-go          #+#    #+#             */
/*   Updated: 2019/02/10 18:23:58 by ggwin-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	char	*s;
	size_t	size;

	size = ft_strlen(src) + 1;
	s = (char *)malloc(sizeof(char) * size);
	if (s == NULL)
		return (NULL);
	return (ft_memmove(s, src, size));
}
