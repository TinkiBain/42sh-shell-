/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector_add.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggwin-go <ggwin-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/19 16:51:28 by ggwin-go          #+#    #+#             */
/*   Updated: 2019/03/20 15:10:45 by ggwin-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	**ft_vector_add(void **arr, void *elem)
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
	++size;
	new_arr = (void **)malloc(sizeof(void *) * (size + 1));
	i = 0;
	if (arr)
		while (arr[i])
		{
			new_arr[i] = arr[i];
			++i;
		}
	new_arr[i] = elem;
	new_arr[++i] = NULL;
	if (arr)
		free(arr);
	return (new_arr);
}
