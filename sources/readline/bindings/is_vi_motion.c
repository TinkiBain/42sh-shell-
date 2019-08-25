/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_vi_motion.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelisan <gmelisan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/15 05:29:03 by gmelisan          #+#    #+#             */
/*   Updated: 2019/08/25 19:43:51 by gmelisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "actions.h"

/*
** All motions besides T, t
*/

int		is_vi_motion(t_action action)
{
	if (action == beginning_of_line
		|| action == backward_word
		|| action == forward_char
		|| action == vi_beginning_of_line_nonblank
		|| action == end_of_line
		|| action == forward_word
		|| action == backward_char
		|| action == vi_find_backward
		|| action == vi_forward_bigword_start
		|| action == vi_repeat_find
		|| action == vi_repeat_find_reverse
		|| action == vi_forward_bigword
		|| action == vi_find_forward
		|| action == vi_forward_word_start
		|| action == vi_goto_char
		|| action == vi_backward_bigword)
		return (1);
	return (0);
}
