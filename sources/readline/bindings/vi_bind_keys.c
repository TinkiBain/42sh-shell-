/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vi_bind_keys.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelisan <gmelisan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/04 10:12:55 by gmelisan          #+#    #+#             */
/*   Updated: 2019/08/15 05:53:34 by gmelisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bindings.h"

static void vi_insert_bind_keys(t_vector *key_bindings)
{
	int i;

	bind(key_bindings, ESC, vi_command);
	bind(key_bindings, BACKSPACE, backward_delete_char);
	bind(key_bindings, DEL, backward_delete_char);
	i = 32;
	while (ft_isprint(i))
		bind(key_bindings, i++, self_insert);
}

static void	vi_command_bind_keys(t_vector *key_bindings)
{
	bind(key_bindings, 'h', backward_char);
	bind(key_bindings, 'l', forward_char);
	bind(key_bindings, 'k', previous_history);
	bind(key_bindings, 'j', next_history);
	bind(key_bindings, ' ', forward_char);
	bind(key_bindings, BACKSPACE, backward_char);
	bind(key_bindings, DEL, backward_char);
	bind(key_bindings, '$', end_of_line);
	bind(key_bindings, '^', vi_beginning_of_line_nonblank);
	bind(key_bindings, '0', beginning_of_line);
	bind(key_bindings, 'x', delete_char);
	bind(key_bindings, 'X', backward_delete_char);
	bind(key_bindings, 'i', vi_insert_at);
	bind(key_bindings, 'I', vi_insert_beginning);
	bind(key_bindings, 'a', vi_insert_after);
	bind(key_bindings, 'A', vi_insert_end);
	bind(key_bindings, 'R', vi_insert_overwrite);
	bind(key_bindings, 'e', forward_word);
	bind(key_bindings, 'b', backward_word);
	bind(key_bindings, 'c', vi_delete_to_motion);
}

void		vi_bind_keys(int vi_mode, t_vector *key_bindings)
{
	bind(key_bindings, CTRL_C, reset_line);
	bind(key_bindings, ARROW_LEFT, backward_char);
	bind(key_bindings, ARROW_RIGHT, forward_char);
	bind(key_bindings, ARROW_UP, previous_history);
	bind(key_bindings, ARROW_DOWN, next_history);
	if (vi_mode == VI_INSERT)
		vi_insert_bind_keys(key_bindings);
	else if (vi_mode == VI_COMMAND)
		vi_command_bind_keys(key_bindings);
}
