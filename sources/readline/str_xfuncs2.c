/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_xfuncs2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelisan </var/spool/mail/vladimir>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/06 18:24:15 by gmelisan          #+#    #+#             */
/*   Updated: 2019/08/01 06:48:17 by gmelisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "str_xfuncs.h"

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

