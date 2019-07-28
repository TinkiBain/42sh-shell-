/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_create.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelisan <gmelisan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 21:33:31 by gmelisan          #+#    #+#             */
/*   Updated: 2019/03/11 01:37:42 by gmelisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

t_string		str_create(size_t len)
{
	t_string str;

	str.alloc = STR_DEFBUFSIZE;
	while (str.alloc <= len)
		str.alloc *= 2;
	str.s = ft_memalloc(str.alloc);
	if (!str.s)
		str_zero(&str);
	else
		str.len = len;
	return (str);
}
