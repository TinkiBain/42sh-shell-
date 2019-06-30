/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector_remove.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggwin-go <ggwin-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/19 16:51:28 by ggwin-go          #+#    #+#             */
/*   Updated: 2019/03/26 12:19:28 by ggwin-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	**ft_vector_remove(void **arr, void *elem)
{
	void	**new_arr;
	size_t	size;
	size_t	i;

	if (!elem)
		return (arr);
	size = 0;
	if (arr)
		while (arr[size])
			++size;
	if (!(new_arr = (void **)malloc(sizeof(void *) * (size + 1))))
		return (arr);
	i = 0;
	size = 0;
	if (arr)
		while (arr[i])
		{
			if (arr[i] != elem)
				new_arr[size++] = arr[i];
			++i;
		}
	new_arr[size] = NULL;
	free(elem);
	free(arr);
	return (new_arr);
}
