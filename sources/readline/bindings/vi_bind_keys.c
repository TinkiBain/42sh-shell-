/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vi_bind_keys.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelisan <gmelisan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/04 10:12:55 by gmelisan          #+#    #+#             */
/*   Updated: 2019/08/16 04:25:08 by gmelisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bindings.h"

static void vi_insert_bind_keys(t_vector *key_bindings)
{
	int i;

	bind(key_bindings, ESC, vi_command);
	bind(key_bindings, BACKSPACE, backward_delete_char);
	bind(key_bindings, DEL, backward_delete_char);
	bind(key_bindings, TAB, complete);
	i = 32;
	while (ft_isprint(i))
		bind(key_bindings, i++, self_insert);
}

static void	vi_command_bind_keys1(t_vector *key_bindings)
{
	bind(key_bindings, BACKSPACE, backward_char);
	bind(key_bindings, DEL, backward_char);
	bind(key_bindings, 'h', backward_char);
	bind(key_bindings, 'l', forward_char);
	bind(key_bindings, 'k', previous_history);
	bind(key_bindings, 'j', next_history);
	bind(key_bindings, ' ', forward_char);
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
	bind(key_bindings, 'b', vi_backward_word);
	bind(key_bindings, 'B', vi_backward_bigword);
	bind(key_bindings, 'e', vi_forward_word);
	bind(key_bindings, 'E', vi_forward_bigword);
	bind(key_bindings, 'w', vi_forward_word_start);
	bind(key_bindings, 'W', vi_forward_bigword_start);
	bind(key_bindings, 'c', vi_delete_to_motion);
	bind(key_bindings, 'C', vi_delete_to_end);
}

static void	vi_command_bind_keys2(t_vector *key_bindings)
{
	bind(key_bindings, ESC, vi_ignore);
	bind(key_bindings, 'S', vi_clear_line);
	bind(key_bindings, '#', vi_comment);
	bind(key_bindings, 'v', vi_vi);
	bind(key_bindings, '|', vi_goto_char);
	bind(key_bindings, 'f', vi_find_forward);
	bind(key_bindings, 'F', vi_find_backward);
	bind(key_bindings, ';', vi_repeat_find);
	bind(key_bindings, ',', vi_repeat_find_reverse);
	bind(key_bindings, 'r', vi_replace);
	bind(key_bindings, 'd', vi_delete_to_motion_save);
	bind(key_bindings, 'D', vi_delete_to_end_save);
	bind(key_bindings, 'p', vi_paste_after);
	bind(key_bindings, 'P', vi_paste_before);
	bind(key_bindings, 'y', vi_yank_to_motion);
	bind(key_bindings, 'Y', vi_yank_to_end);
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
	{
		vi_command_bind_keys1(key_bindings);
		vi_command_bind_keys2(key_bindings);
	}
}
