/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector_add.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggwin-go <ggwin-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 15:57:38 by ggwin-go          #+#    #+#             */
/*   Updated: 2019/06/11 19:13:22 by ggwin-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vector.h"
#include "libft.h"

static void	realloc_vector_data(t_vector *vector)
{
	void	**tmp;
	size_t	i;

	vector->capacity += SIZE_DELTA;
	tmp = (void **)ft_xmalloc(sizeof(void *) * vector->capacity);
	ft_bzero(tmp, vector->capacity);
	i = 0;
	while (i < vector->count)
	{
		*(tmp + i) = *(vector->data + i);
		++i;
	}
	free(vector->data);
	vector->data = tmp;
}

int			ft_vector_add(t_vector *vector, void *elem)
{
	void	**arr;

	if (!elem)
		return (0);
	if (vector->capacity == (vector->count + 1))
		realloc_vector_data(vector);
	arr = vector->data;
	arr[vector->count] = elem;
	++(vector->count);
	return (1);
}
