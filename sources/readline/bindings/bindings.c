/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bindings.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelisan <gmelisan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/06 19:43:02 by gmelisan          #+#    #+#             */
/*   Updated: 2019/09/19 15:24:49 by gmelisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bindings.h"
#include "del_funcs.h"

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

void		clear_bindings(t_vector *key_bindings)
{
	vec_delete(key_bindings, del_bind_str);
}
