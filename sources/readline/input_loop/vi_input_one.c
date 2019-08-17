/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vi_input_one.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelisan <gmelisan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/17 16:22:40 by gmelisan          #+#    #+#             */
/*   Updated: 2019/08/17 17:15:38 by gmelisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "input_loop.h"

static int		check_arg(t_line *line)
{
	if (line->vi_mode != VI_COMMAND)
		return (0);
	if (str_get(line->keybuf, 0) == '0' && line->reading_arg == 0)
		return (0);
	if (ft_isdigit(str_get(line->keybuf, 0)) && line->reading_arg == 0)
	{
		line->reading_arg = 1;
		line->arg = line->keybuf.s[0] - '0';
		return (1);
	}
	if (ft_isdigit(str_get(line->keybuf, 0)) && line->reading_arg)
	{
		line->arg = line->arg * 10 + line->keybuf.s[0] - '0';
		return (1);
	}
	line->reading_arg = 0;
	return (0);
}

static int		perform_action_one(t_line *line)
{
	t_binding	*b;

	if (check_arg(line))
		return (0);
	b = find_binding(&line->key_bindings, line->keybuf);
	if (b && (line->action = b->action))
	{
		line->action(line);
		line->arg = 1;
	}
	return (1);
}

int				vi_input_one(t_line *line)
{
	int		ret;

	line->keybuf = str_create(KEYBUF_SIZE);
	while ((ret = read(STDIN, line->keybuf.s, KEYBUF_SIZE - 1)) &&
			*line->keybuf.s != NL)
	{
		if (perform_action_one(line))
		{
			loginfo_line(line);
			return (1);
		}
		loginfo_line(line);
		ft_bzero(line->keybuf.s, KEYBUF_SIZE);
	}
	if (ret < 0)
		g_errno = E_READ;
	return (0);
}
