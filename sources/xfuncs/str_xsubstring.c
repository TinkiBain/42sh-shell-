/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_xsubstring.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelisan <gmelisan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/24 18:51:14 by gmelisan          #+#    #+#             */
/*   Updated: 2019/10/14 02:01:38 by gmelisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "xfuncs.h"

t_string		str_xsubstring(t_string str, int start, int len)
{
	t_string new;

	new = str_substring(str, start, len);
	if (!new.s)
		die();
	return (new);
}
