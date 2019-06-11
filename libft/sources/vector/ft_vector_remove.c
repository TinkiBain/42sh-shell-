/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector_remove.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggwin-go <ggwin-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/19 16:51:28 by ggwin-go          #+#    #+#             */
/*   Updated: 2019/06/11 19:06:58 by ggwin-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_vector.h"

int	ft_vector_remove(t_vector *vector, void *elem)
{
	void	**arr;
	void	**new_arr;
	size_t	size;
	size_t	i;

	if (!elem)
		return (0);
	arr = vector->data;
	new_arr = (void **)ft_xmalloc(sizeof(void *) * vector->capacity);
	ft_bzero(new_arr, sizeof(void *) * vector->capacity);
	i = 0;
	size = 0;
	if (arr)
		while (arr[i])
		{
			if (arr[i] != elem)
				new_arr[size++] = arr[i];
			++i;
		}
	vector->data = new_arr;
	free(elem);
	free(arr);
	return (1);
}
