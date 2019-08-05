/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bindings.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelisan </var/spool/mail/vladimir>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/06 19:43:02 by gmelisan          #+#    #+#             */
/*   Updated: 2019/08/05 16:58:38 by gmelisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bindings.h"

void		update_bindings(int vi_mode, t_vector *key_bindings)
{
	clear_bindings(key_bindings);
	*key_bindings = vec_xcreate(0, sizeof(t_binding));
	if (!vi_mode)
		bind_keys(key_bindings); 
	else
		vi_bind_keys(vi_mode, key_bindings);
}

void		init_bindings(int vi_mode, t_vector *key_bindings)
{
	*key_bindings = vec_xcreate(0, sizeof(t_binding));
	if (!vi_mode)
		bind_keys(key_bindings); 
	else
		vi_bind_keys(vi_mode, key_bindings);
}

static void del(void *elem)
{
	str_delete(&((t_binding *)elem)->sequence);
}

void		clear_bindings(t_vector *key_bindings)
{
	vec_delete(key_bindings, del);
}
