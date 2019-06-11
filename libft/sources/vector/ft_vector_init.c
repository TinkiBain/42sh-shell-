/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector_init.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggwin-go <ggwin-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 14:45:33 by ggwin-go          #+#    #+#             */
/*   Updated: 2019/06/11 18:03:14 by ggwin-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_vector.h"

t_vector	*ft_vector_init(void *elem)
{
	t_vector	*res;
	void		**arr;

	res = (t_vector *)ft_xmalloc(sizeof(t_vector));
	arr = (void **)ft_xmalloc(sizeof(void *) * SIZE_DELTA);
	ft_bzero(arr, sizeof(void *) * SIZE_DELTA);
	if (elem)
		*arr = elem;
	res->data = arr;
	res->count = (elem) ? 1 : 0;
	res->capacity = SIZE_DELTA;
	return (res);
}
