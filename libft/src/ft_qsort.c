/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_qsort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelisan <gmelisan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 00:24:21 by gmelisan          #+#    #+#             */
/*   Updated: 2019/02/13 11:48:22 by gmelisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_qsort.h"

static void		*get_i(struct s_qsortarr *a, int i)
{
	return ((char *)a->arr + (i * a->size));
}

static int		partition(struct s_qsortarr *a, int first, int last)
{
	void	*pivot;
	int		i;
	int		j;

	pivot = get_i(a, last);
	i = first - 1;
	j = first;
	while (j <= last - 1)
	{
		if (a->cmp(get_i(a, j), pivot) <= 0)
		{
			i++;
			ft_swap(get_i(a, i), get_i(a, j), a->size);
		}
		j++;
	}
	ft_swap(get_i(a, i + 1), get_i(a, last), a->size);
	return (i + 1);
}

static void		quicksort(struct s_qsortarr *a, int first, int last)
{
	int q;

	if (first < last)
	{
		q = partition(a, first, last);
		quicksort(a, first, q - 1);
		quicksort(a, q + 1, last);
	}
}

void			ft_qsort(void *ptr, size_t count, size_t size,
							int (*cmp)(const void *, const void *))
{
	struct s_qsortarr qsortarr;

	qsortarr.arr = ptr;
	qsortarr.size = size;
	qsortarr.cmp = cmp;
	quicksort(&qsortarr, 0, count - 1);
}
