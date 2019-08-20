/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggwin-go <ggwin-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/07 21:16:01 by gmelisan          #+#    #+#             */
/*   Updated: 2019/08/20 12:06:05 by gmelisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void		del_bind_str(void *elem)
{
	str_delete(&((t_binding *)elem)->sequence);
}

void		del_str(void *s)
{
	str_delete(s);
}

void		del_pchar(void *s)
{
	ft_strdel((char **)s);
}

int			cmp_pstring(const void *a, const void *b)
{
	return (ft_strcmp(((t_string *)a)->s,
					  ((t_string *)b)->s));
}
