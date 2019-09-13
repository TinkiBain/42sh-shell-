/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vi_input_loop.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggwin-go <ggwin-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/04 11:54:06 by gmelisan          #+#    #+#             */
/*   Updated: 2019/09/13 12:34:12 by gmelisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_readline.h"

extern t_opt	g_opt;

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

static int		perform_action(t_line *line)
{
	t_binding	*b;

	if (check_arg(line))
		return (0);
	if (line->arg > 1024)
		line->arg = 1024;
	b = find_binding(&line->key_bindings, line->keybuf);
	if (b && (line->action = b->action))
	{
		line->action(line);
		if (line->vi_mode == VI_COMMAND && line->cpos == (int)line->str->len
			&& line->cpos != 0)
			line->cpos--;
		update_bindings(line->vi_mode, &line->key_bindings);
		update_line(line, 0);
		line->arg = 1;
	}
	return (1);
}

static void		loop_buffer(t_line *line, char keybuf[KEYBUF_SIZE])
{
	int i;

	i = -1;
	while (++i < KEYBUF_SIZE)
	{
		line->keybuf = str_xncopy(keybuf + i, 1);
		perform_action(line);
		str_delete(&line->keybuf);
	}
}

int				vi_input_loop(t_line *line)
{
	char	keybuf[KEYBUF_SIZE];
	int		ret;

	ft_bzero(keybuf, KEYBUF_SIZE);
	while ((ret = read(g_opt.rl_in, keybuf, KEYBUF_SIZE - 1)) > 0)
	{
		if (*keybuf == CTRL_D && line->str->len == 0)
			return (0);
		if (is_ansiseq(keybuf))
		{
			line->keybuf = str_xcopy(keybuf);
			perform_action(line);
		}
		else
			loop_buffer(line, keybuf);
		if (line->action == vi_comment || line->action == vi_vi ||
			*keybuf == CTRL_D || *keybuf == NL)
			return (ret);
		str_delete(&line->keybuf);
		ft_bzero(keybuf, KEYBUF_SIZE);
	}
	return (ret);
}
