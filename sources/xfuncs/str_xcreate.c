/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_xcreate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelisan <gmelisan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 01:58:18 by gmelisan          #+#    #+#             */
/*   Updated: 2019/10/14 01:58:31 by gmelisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "xfuncs.h"

t_string		str_xcreate(size_t len)
{
	t_string str;

	str = str_create(len);
	if (!str.s)
		die();
	return (str);
}
