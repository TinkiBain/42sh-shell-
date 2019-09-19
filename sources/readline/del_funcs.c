/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del_funcs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelisan <gmelisan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 14:46:27 by gmelisan          #+#    #+#             */
/*   Updated: 2019/09/19 15:57:38 by gmelisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "del_funcs.h"
#include "bindings.h"

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

void		del_undo_one(void *p, size_t i)
{
	if (i)
		;
	if (p)
		str_delete(&((t_undo_item *)p)->string);
	free(p);
}
