/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_copy.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelisan <gmelisan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 21:36:00 by gmelisan          #+#    #+#             */
/*   Updated: 2019/09/22 21:30:47 by gmelisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

t_string		str_copy(const char *s)
{
	t_string str;

	str.s = NULL;
	str.len = 0;
	str.alloc = 0;
	if (!s)
		return (str);
	str = str_create(ft_strlen(s));
	if (!str.s)
		return (str);
	ft_memcpy(str.s, s, str.len);
	return (str);
}
