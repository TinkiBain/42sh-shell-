/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelisan <gmelisan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 13:57:06 by gmelisan          #+#    #+#             */
/*   Updated: 2018/12/05 18:32:26 by gmelisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		*ft_range(int min, int max)
{
	int *array;
	int size;
	int i;

	size = max - min;
	if (size <= 0)
		return (NULL);
	array = (int*)malloc(sizeof(*array) * size);
	if (!array)
		return (NULL);
	i = 0;
	while (i < size)
	{
		array[i] = i + min;
		i++;
	}
	return (array);
}
