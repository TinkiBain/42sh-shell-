/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggwin-go <ggwin-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/07 21:16:01 by gmelisan          #+#    #+#             */
/*   Updated: 2019/08/17 08:27:33 by gmelisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

char		*convert_tilde(char *str)
{
	char		*home;
	t_string	res;

	if (!(str[0] == '~' && str[1] == '/'))
		return (ft_xstrdup(str));
	home = getenv("HOME");
	if (!home || !str)
		return (NULL);
	res = str_xcopy(home);
	str_xaddback(&res, "/", 1);
	if (str[0] == '~' && str[1] == '/')
		str_xaddback(&res, str + 2, ft_strlen(str) - 2);
	else
		str_delete(&res);
	return (res.s);
}

void		del_bind_str(void *elem)
{
	str_delete(&((t_binding *)elem)->sequence);
}

void		del_str(void *s)
{
	str_delete(s);
}

int			cmp(const void *a, const void *b)
{
	return (ft_strcmp(((t_string *)a)->s,
					  ((t_string *)b)->s));
}
