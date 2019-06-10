/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggwin-go <ggwin-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 16:13:07 by ggwin-go          #+#    #+#             */
/*   Updated: 2019/02/10 18:25:32 by ggwin-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrev(char *src, int need_to_free)
{
	size_t	len;
	char	*res;
	char	*start;
	char	*end;
	char	ch;

	res = ft_strdup(src);
	len = ft_strlen((const char *)res);
	start = res;
	end = &start[len - 1];
	while (start < end)
	{
		ch = *start;
		*(start++) = *end;
		*(end--) = ch;
	}
	if (need_to_free)
		free(src);
	return (res);
}
