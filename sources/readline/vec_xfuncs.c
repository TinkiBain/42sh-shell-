/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_xfuncs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelisan </var/spool/mail/vladimir>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 16:51:18 by gmelisan          #+#    #+#             */
/*   Updated: 2019/08/01 06:48:52 by gmelisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vec_xfuncs.h"

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
