/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_loop.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelisan </var/spool/mail/vladimir>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 16:40:53 by gmelisan          #+#    #+#             */
/*   Updated: 2019/08/17 09:14:06 by gmelisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "input_loop.h"

static int		check_arg(t_line *line) 
{
	if (line->keybuf[0] == ESC && ft_isdigit(line->keybuf[1]))
	{
		line->reading_arg = 1;
		line->arg = line->keybuf[1] - '0';
		return (1);
	}
	if (ft_isdigit(line->keybuf[0]) && line->reading_arg)
	{
		line->arg = line->arg * 10 + line->keybuf[0] - '0';
		return (1);
	}
	line->reading_arg = 0;
	return (0);
}

static void		check_hs(t_line *line, t_action action)
{
	if (action != &self_insert &&
		action != &backward_delete_char	&&
		action != &reverse_search_history)
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
	b = find_binding(&line->key_bindings, line->keybuf);
	if (b && (line->action = b->action))
	{
		line->action(line);
		check_hs(line, line->action);
		update_line(line);
		if (line->hs_mode)
			hs_clear(line);
		line->arg = 1;
	}
}

static int		is_ansiseq(char buf[KEYBUF_SIZE])
{
	if (buf[0] == ESC && (buf[1] == '[' || buf[1] == 'O'))
		return (1);
	return (0);
}

int				input_loop(t_line *line)
{
	int		ret;
	
	if (line->vi_mode)
		return (vi_input_loop(line));
	while ((ret = read(g_rl_options.tty, line->keybuf, 1) > 0 && *line->keybuf != NL))
	{
		if (*line->keybuf == ESC)
		{
			if ((ret = read(g_rl_options.tty, line->keybuf + 1, 1)) <= 0)
				break ;
			if (is_ansiseq(line->keybuf))
				if ((ret = read(g_rl_options.tty, line->keybuf + 2, KEYBUF_SIZE - 3)) <= 0)
					break ;
		}
		if (*line->keybuf == CTRL_D && line->str->len == 0)
			return (1);
		perform_action(line);
		loginfo_line(line);
		ft_bzero(line->keybuf, KEYBUF_SIZE);
	}
	if (ret < 0)
		g_errno = E_READ;
	return (0);
}
