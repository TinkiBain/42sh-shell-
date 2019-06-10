/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup_len.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggwin-go <ggwin-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 19:13:11 by ggwin-go          #+#    #+#             */
/*   Updated: 2019/02/12 15:30:00 by ggwin-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup_len(const char *src, size_t *len)
{
	char	*s;

	*len = ft_strlen(src);
	s = (char *)malloc(sizeof(char) * (*len + 1));
	if (s == NULL)
		return (NULL);
	return (ft_memmove(s, src, (*len + 1)));
}
