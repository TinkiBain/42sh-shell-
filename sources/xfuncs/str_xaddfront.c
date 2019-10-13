/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_xaddfront.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelisan <gmelisan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 02:07:22 by gmelisan          #+#    #+#             */
/*   Updated: 2019/10/14 02:07:25 by gmelisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "xfuncs.h"

void			str_xaddfront(t_string *str, const char *s, size_t size)
{
	if (!str)
		return ;
	if (!(str_addfront(str, s, size)))
		die();
}
