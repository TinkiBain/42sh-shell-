/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_xfuncs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggwin-go <ggwin-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/24 18:50:43 by ggwin-go          #+#    #+#             */
/*   Updated: 2019/08/24 18:50:45 by ggwin-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "xfuncs.h"

t_vector		vec_xcreate(size_t len, size_t size)
{
	t_vector vec;

	vec = vec_create(len, size);
	if (!vec.v)
		die();
	return (vec);
}

t_vector		vec_xduplicate(t_vector vec, void *(*duplicate)(void *))
{
	t_vector new;

	new = vec_duplicate(vec, duplicate);
	if (!new.v)
		die();
	return (new);
}

void			vec_xaddback(t_vector *vec, void *new)
{
	if (!vec)
		return ;
	if (!(vec_addback(vec, new)))
		die();
}

void			vec_xaddfront(t_vector *vec, void *new)
{
	if (!vec)
		return ;
	if (!(vec_addfront(vec, new)))
		die();
}
