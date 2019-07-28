/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_duplicate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelisan <gmelisan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 22:56:33 by gmelisan          #+#    #+#             */
/*   Updated: 2019/07/06 19:25:32 by gmelisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

t_string		str_duplicate(t_string str)
{
	t_string new;

	new = str_create(str.len);
	if (new.s)
		ft_memcpy(new.s, str.s, str.len);
	return (new);
}
