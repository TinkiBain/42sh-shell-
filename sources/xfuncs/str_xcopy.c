/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_xcopy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelisan <gmelisan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 02:00:40 by gmelisan          #+#    #+#             */
/*   Updated: 2019/10/14 02:00:41 by gmelisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "xfuncs.h"

t_string		str_xcopy(const char *s)
{
	t_string str;

	str = str_copy(s);
	if (s && !str.s)
		die();
	return (str);
}
