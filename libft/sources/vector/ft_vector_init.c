/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector_init.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggwin-go <ggwin-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 14:45:33 by ggwin-go          #+#    #+#             */
/*   Updated: 2019/06/10 15:56:46 by ggwin-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_vector.h"

t_vector	*ft_vector_init(void *elem)
{
	t_vector	*res;
	size_t		size;

	res = (t_vector *)malloc(sizeof(t_vector));
	res->data = (void **)malloc(sizeof(void *) * SIZE_DELTA);
	ft_bzero(res, sizeof(void *) * SIZE_DELTA);
	if (elem)
	{
		res->count = 1;
		*(res->data) = elem;
	}
	else
		res->count = 0;
	res->capacity = SIZE_DELTA;
	return (res);
}
