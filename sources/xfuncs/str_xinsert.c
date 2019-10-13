/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_xinsert.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelisan <gmelisan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/06 18:24:15 by gmelisan          #+#    #+#             */
/*   Updated: 2019/10/14 02:08:11 by gmelisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "xfuncs.h"

void			str_xinsert(t_string *str, int to, const char *s, size_t size)
{
	if (!str)
		return ;
	if (!(str_insert(str, to, s, size)))
		die();
}
