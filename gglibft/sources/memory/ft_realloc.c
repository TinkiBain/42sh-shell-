/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggwin-go <ggwin-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 12:31:11 by ggwin-go          #+#    #+#             */
/*   Updated: 2019/02/10 18:20:17 by ggwin-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_realloc(void *ptr, size_t size)
{
	unsigned char	*new;
	unsigned char	*tmp;
	void			*res;

	new = (size == 0) ? NULL : (unsigned char *)malloc(size);
	res = (void *)new;
	tmp = (unsigned char *)ptr;
	if (ptr)
	{
		if (new)
		{
			while (size-- && *tmp)
			{
				*(new++) = *(tmp++);
			}
			while (size--)
				*(new++) = 0;
		}
		free(ptr);
	}
	return (res);
}
