/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_addfront.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelisan <gmelisan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/01 16:49:22 by gmelisan          #+#    #+#             */
/*   Updated: 2019/09/22 21:37:00 by gmelisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

static t_string	*create(t_string *str, const char *s, size_t size)
{
	*str = str_create(size);
	if (!str->alloc)
		return (NULL);
	ft_memcpy(str->s, s, size);
	return (str);
}

t_string		*str_addfront(t_string *str, const char *s, size_t size)
{
	size_t	newalloc;

	if (!str || !s || !size)
		return (str);
	if (!str->alloc)
		return (create(str, s, size));
	if (str->len + size >= str->alloc)
	{
		newalloc = str->alloc * 2;
		while (str->len + size >= newalloc)
			newalloc *= 2;
		if (!ft_realloc((void **)&str->s, str->len, newalloc))
			return (NULL);
		str->alloc = newalloc;
	}
	ft_memmove(str->s + size, str->s, str->len);
	ft_memcpy(str->s, s, size);
	str->len += size;
	return (str);
}
