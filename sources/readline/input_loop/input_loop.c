/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_loop.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelisan <gmelisan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 16:40:53 by gmelisan          #+#    #+#             */
/*   Updated: 2019/09/03 22:48:44 by gmelisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "input_loop.h"

/*
** 1 - exit, 0 - continue
*/

int				input_loop(t_line *line)
{
	int		ret;

	if (line->vi_mode)
		ret = vi_input_loop(line);
	else
		ret = em_input_loop(line);
	if (ret < 0)
		print_error("Read error", NULL);
	history_expand(line);
	line->cpos = line->str->len;
	if (line->vi_mode || line->emacs_mode)
		update_line(line);
	if (ret <= 0 && line->oldstr.len == 0)
		return (1);
	return (0);
}
