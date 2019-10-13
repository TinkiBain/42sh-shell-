/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_xncopy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelisan <gmelisan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 02:01:13 by gmelisan          #+#    #+#             */
/*   Updated: 2019/10/14 02:01:14 by gmelisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "xfuncs.h"

t_string		str_xncopy(const char *s, int n)
{
	t_string str;

	str = str_ncopy(s, n);
	if (s && !str.s)
		die();
	return (str);
}
