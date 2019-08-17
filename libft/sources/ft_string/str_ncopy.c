/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_ncopy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelisan <gmelisan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/17 14:17:56 by gmelisan          #+#    #+#             */
/*   Updated: 2019/08/17 14:20:02 by gmelisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

t_string	str_ncopy(char *s, int n)
{
	t_string	str;

	str.s = NULL;
	str.len = 0;
	str.alloc = 0;
	if (!s)
		return (str);
	str = str_create(n);
	if (!str.s)
		return (str);
	ft_memcpy(str.s, s, str.len);
	return (str);
}
