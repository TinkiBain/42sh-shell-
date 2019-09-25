/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_loop.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelisan <gmelisan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 16:40:53 by gmelisan          #+#    #+#             */
/*   Updated: 2019/09/25 23:09:31 by gmelisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "input_loop.h"

/*
** 1 - ft_readline() returns NULL
** 0 - ft_readline() returns string
*/

int				input_loop(t_line *line)
{
	extern int	g_eof;
	int			ret;
	char		keybuf[KEYBUF_SIZE];

	loginfo("Start reading loop");
	if (line->vi_mode)
		ret = vi_input_loop(line, keybuf);
	else
		ret = em_input_loop(line, keybuf);
	loginfo("End reading loop");
	if (ret < 0)
		print_error("Read error", line->str->s);
	if (line->mode != RL_HEREDOC && !history_expand(line))
		return (1);
	line->cpos = line->str->len;
	if ((line->vi_mode || line->emacs_mode) && (line->action != vi_vi))
		update_line(line, 0);
	if (ret == 0 && *keybuf == CTRL_C)
		return (1);
	if (ret == 0 && *keybuf == CTRL_D
		&& (g_eof = 1))
		return (1);
	return (0);
}
