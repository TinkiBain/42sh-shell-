/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_xfuncs2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggwin-go <ggwin-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/06 18:24:15 by gmelisan          #+#    #+#             */
/*   Updated: 2019/08/24 18:27:29 by ggwin-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "xfuncs.h"

void			str_xaddback(t_string *str, char *s, size_t size)
{
	if (!str)
		return ;
	if (!(str_addback(str, s, size)))
		die();
}

void			str_xaddfront(t_string *str, char *s, size_t size)
{
	if (!str)
		return ;
	if (!(str_addfront(str, s, size)))
		die();
}

void			str_xinsert(t_string *str, int to, char *s, size_t size)
{
	if (!str)
		return ;
	if (!(str_insert(str, to, s, size)))
		die();
}
