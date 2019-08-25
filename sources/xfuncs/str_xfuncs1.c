/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_xfuncs1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggwin-go <ggwin-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/24 18:51:14 by ggwin-go          #+#    #+#             */
/*   Updated: 2019/08/24 18:51:48 by ggwin-go         ###   ########.fr       */
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

t_string		str_xncopy(char *s, int n)
{
	t_string str;

	str = str_ncopy(s, n);
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
