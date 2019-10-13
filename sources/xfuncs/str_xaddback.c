/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_xaddback.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelisan <gmelisan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 02:02:06 by gmelisan          #+#    #+#             */
/*   Updated: 2019/10/14 02:02:09 by gmelisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "xfuncs.h"

void			str_xaddback(t_string *str, const char *s, size_t size)
{
	if (!str)
		return ;
	if (!(str_addback(str, s, size)))
		die();
}
