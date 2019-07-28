/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_delete.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelisan <gmelisan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/10 18:09:23 by gmelisan          #+#    #+#             */
/*   Updated: 2019/03/10 18:47:56 by gmelisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vector.h"

void	vec_delete(t_vector *vec, void (*del)(void *))
{
	int i;

	if (vec->alloc > 0)
	{
		i = 0;
		while ((size_t)i < vec->len)
		{
			del(vec_get(*vec, i));
			i++;
		}
		ft_memdel((void **)&vec->v);
	}
	vec_zero(vec);
}
