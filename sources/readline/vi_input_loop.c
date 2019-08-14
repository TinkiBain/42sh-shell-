/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vi_input_loop.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelisan <gmelisan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/04 11:54:06 by gmelisan          #+#    #+#             */
/*   Updated: 2019/08/14 17:53:08 by gmelisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_readline.h"

static int		check_arg(t_line *line)
{
	if (line->vi_mode != VI_COMMAND)
		return (0);
	if (line->keybuf[0] > '0' && line->keybuf[0] <= '9')
	{
		line->reading_arg = 1;
		line->arg = line->keybuf[0] - '0';
		return (1);
	}
	if (line->keybuf[0] > 0 && line->keybuf[0] <= 9 && line->reading_arg)
	{
		line->arg = line->arg * 10 + line->keybuf[0] - '0';
		return (1);
	}
	line->reading_arg = 0;
	return (0);
}

static void		perform_action(t_line *line)
{
	t_binding	*b;

	if (check_arg(line))
		return ;
	b = find_binding(&line->key_bindings, line->keybuf);
	if (b && b->action)
	{
		(*b->action)(line);
		if (line->vi_mode == VI_COMMAND && line->cpos == (int)line->str->len
			&& line->cpos != 0)
			line->cpos--;
		update_bindings(line->vi_mode, &line->key_bindings);
		update_line(line);
		line->arg = 1;
	}
}

int				vi_input_loop(t_line *line)
{
	int		ret;

	while ((ret = read(STDIN, line->keybuf, KEYBUF_SIZE - 1)) &&
			*line->keybuf != NL)
	{
		if (line->keybuf[0] == CTRL_D && line->str->len == 0)
			return (1);
		else if (line->keybuf[0] == CTRL_D)
			return (0);
		perform_action(line);
		loginfo_line(line);
		ft_bzero(line->keybuf, KEYBUF_SIZE);
	}
	if (ret < 0)
		g_errno = E_READ;
	return (0);
}
