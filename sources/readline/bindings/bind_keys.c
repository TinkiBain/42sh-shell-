/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bind_keys.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelisan <gmelisan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/04 10:06:41 by gmelisan          #+#    #+#             */
/*   Updated: 2019/08/09 04:43:41 by gmelisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bindings.h"

static void	bind_keys1(t_vector *key_bindings)
{
	bind(key_bindings, ARROW_LEFT, backward_char);
	bind(key_bindings, ARROW_RIGHT, forward_char);
	bind(key_bindings, ARROW_UP, previous_history);
	bind(key_bindings, ARROW_DOWN, next_history);
	bind(key_bindings, CTRL_P, previous_history);
	bind(key_bindings, CTRL_N, next_history);
	bind(key_bindings, CTRL_LEFT, backward_word);
	bind(key_bindings, CTRL_RIGHT, forward_word);
	bind(key_bindings, CTRL_UP, backward_line);
	bind(key_bindings, CTRL_DOWN, forward_line);
	bind(key_bindings, CTRL_B, backward_char);
	bind(key_bindings, CTRL_F, forward_char);
	bind(key_bindings, BACKSPACE, backward_delete_char);
	bind(key_bindings, DEL, backward_delete_char);
	bind(key_bindings, CTRL_D, delete_char);
	bind(key_bindings, DELETE, delete_char);
	bind(key_bindings, CTRL_A, beginning_of_line);
	bind(key_bindings, HOME, beginning_of_line);
	bind(key_bindings, END, end_of_line);
	bind(key_bindings, INSERT, overwrite_mode);
	bind(key_bindings, CTRL_E, end_of_line);
	bind(key_bindings, ENTER, self_insert);
	bind(key_bindings, CTRL_L, clear_screen);
	bind(key_bindings, CTRL_T, transpose_chars);
	bind(key_bindings, META + 't', transpose_words);
}

static void bind_keys2(t_vector *key_bindings)
{
	bind(key_bindings, CTRL_C, reset_line);
	bind(key_bindings, CTRL_K, kill_line);
	bind(key_bindings, CTRL_U, unix_line_discard);
	bind(key_bindings, CTRL_W, unix_word_rubout);
	bind(key_bindings, CTRL_Y, yank);
	bind(key_bindings, CTRL_R, reverse_search_history);
	bind(key_bindings, CTRL_G, reset_history_search);
	bind(key_bindings, META + '/', possible_filename_completions);
	bind(key_bindings, TAB, complete);
}

void		bind_keys(t_vector *key_bindings)
{
	int i;

	i = 32;
	while (ft_isprint(i))
		bind(key_bindings, i++, self_insert);
	bind_keys1(key_bindings);
	bind_keys2(key_bindings);
}
