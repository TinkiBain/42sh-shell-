/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_substring.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelisan <gmelisan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/28 17:32:25 by gmelisan          #+#    #+#             */
/*   Updated: 2019/02/28 17:36:41 by gmelisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

t_string		str_substring(t_string str, int start, int len)
{
	t_string new;

	new = str_create(len);
	if (new.s)
		ft_memcpy(new.s, &(str.s[start]), len);
	return (new);
}
