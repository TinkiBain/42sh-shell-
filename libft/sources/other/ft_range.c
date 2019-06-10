/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggwin-go <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 19:33:41 by ggwin-go          #+#    #+#             */
/*   Updated: 2018/11/25 18:25:08 by ggwin-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	unsigned int	size;
	unsigned int	i;
	int				*arr;

	if (min >= max)
		return (NULL);
	else
	{
		size = max - min;
		arr = (int *)malloc(sizeof(int) * (size + 1));
		i = 0;
		while (i <= size)
			arr[i++] = min++;
		return (arr);
	}
}
