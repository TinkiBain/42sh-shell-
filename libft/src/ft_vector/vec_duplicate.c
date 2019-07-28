/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_duplicate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelisan <gmelisan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/10 18:06:42 by gmelisan          #+#    #+#             */
/*   Updated: 2019/07/26 19:10:15 by gmelisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vector.h"

t_vector	vec_duplicate(t_vector vec, void *(*duplicate)(void *))
{
	t_vector	new;
	void		*tmp;
	int			i;

	new = vec_create(vec.len, vec.size);
	i = 0;
	while (i < (int)new.len)
	{
		tmp = (duplicate ? duplicate(vec_get(vec, i)) : vec_get(vec, i));
		ft_memcpy(vec_get(new, i), tmp, vec.size);
		i++;
	}
	return (new);
}
