/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_create.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggwin-go <ggwin-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/08 16:57:43 by gmelisan          #+#    #+#             */
/*   Updated: 2019/07/28 20:38:54 by ggwin-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vector.h"

t_vector	vec_create(size_t len, size_t size)
{
	t_vector	vec;
	size_t		bytelen;

	vec.alloc = VEC_DEFBUFSIZE;
	vec.size = size;
	bytelen = (len + 1) * size;
	while (vec.alloc <= bytelen)
		vec.alloc *= 2;
	vec.v = ft_memalloc(vec.alloc);
	if (!vec.v)
		vec_zero(&vec);
	else
		vec.len = len;
	return (vec);
}
