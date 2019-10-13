/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   em_input_loop.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelisan <gmelisan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/17 15:15:42 by gmelisan          #+#    #+#             */
/*   Updated: 2019/10/13 12:36:44 by gmelisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "input_loop.h"

extern t_opt	g_opt;

static int		check_arg(t_line *line)
{
	if (str_get(line->keybuf, 0) == ESC &&
		ft_isdigit(str_get(line->keybuf, 1)))
	{
		line->reading_arg = 1;
		line->arg = line->keybuf.s[1] - '0';
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

static void		check_hs(t_line *line, t_action action)
{
	if (action != &self_insert
		&& action != &backward_delete_char
		&& action != &reverse_search_history)
		line->hs_mode = 0;
	if (line->hs_mode)
		hs_prepare_line(line);
	else
		str_delete(&line->hs.query);
}

static void		perform_action(t_line *line)
{
	t_binding	*b;

	if (check_arg(line))
		return ;
	if (line->arg > CMD_MAXARG)
		line->arg = CMD_MAXARG;
	b = find_binding(&line->key_bindings, line->keybuf);
	if (b && (line->action = b->action))
	{
		line->action(line);
		check_hs(line, line->action);
		update_line(line, 0);
		if (line->hs_mode)
			hs_clear(line);
		line->arg = 1;
	}
}

int				em_input_loop(t_line *line, char keybuf[KEYBUF_SIZE])
{
	int		ret;

	ft_bzero(keybuf, KEYBUF_SIZE);
	while ((ret = read(g_opt.rl_in, keybuf, 1)) > 0 && *keybuf != NL)
	{
		if (*keybuf == CTRL_C || (*keybuf == CTRL_D && line->str->len == 0))
			return (0);
		if (*keybuf == ESC)
		{
			if ((ret = read(g_opt.rl_in, keybuf + 1, 1)) < 0)
				return (ret);
			if (is_ansiseq(keybuf))
				if ((ret = read(g_opt.rl_in, keybuf + 2, KEYBUF_SIZE - 3)) < 0)
					return (ret);
		}
		line->keybuf = str_xcopy(keybuf);
		perform_action(line);
		loginfo_line(line);
		str_delete(&line->keybuf);
		ft_bzero(keybuf, KEYBUF_SIZE);
	}
	return (ret);
}
