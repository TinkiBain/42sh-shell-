/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vi_input_loop.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelisan <gmelisan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/04 11:54:06 by gmelisan          #+#    #+#             */
/*   Updated: 2019/08/04 11:57:48 by gmelisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_readline.h"

int				vi_input_loop(t_line *line, t_vector *key_bindings)
{
	int		ret;

	while ((ret = read(STDIN, line->keybuf, KEYBUF_SIZE - 1)) &&
			*line->keybuf != NL)
	{
		if (line->keybuf[0] == ESC && line->keybuf[1] == 0)
			line->vi_mode = VI_COMMAND;
		if (!key_bindings)
			break ;
		
	}
	return (0);
}
