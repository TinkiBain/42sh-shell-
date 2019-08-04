/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_xfuncs1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelisan </var/spool/mail/vladimir>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/06 18:14:18 by gmelisan          #+#    #+#             */
/*   Updated: 2019/08/01 06:45:22 by gmelisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "str_xfuncs.h"

t_string		str_xcreate(size_t len)
{
	t_string str;
	
	str = str_create(len);
	if (!str.s)
		die();
	return (str);
}

t_string		str_xduplicate(t_string str)
{
	t_string new;

	new = str_duplicate(str);
	if (!new.s)
		die();
	return (new);
}

t_string		str_xcopy(char *s)
{
	t_string str;

	str = str_copy(s);
	if (s && !str.s)
		die();
	return (str);
}

t_string		str_xsubstring(t_string str, int start, int len)
{
	t_string new;

	new = str_substring(str, start, len);
	if (!new.s)
		die();
	return (new);
}
