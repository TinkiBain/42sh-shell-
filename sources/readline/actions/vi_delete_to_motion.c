/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vi_delete_to_motion.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelisan </var/spool/mail/vladimir>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/15 05:07:21 by gmelisan          #+#    #+#             */
/*   Updated: 2019/08/15 08:27:26 by gmelisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "actions.h"

static int	ignore_arg(t_action action)
{
	if (action == beginning_of_line
		|| action == vi_beginning_of_line_nonblank
		|| action == end_of_line)
		return (1);
	return (0);
}

static void	delete_right(t_line *line, int count)
{
	str_remove(line->str, line->cpos, count);
}

static void	delete_left(t_line *line, int count)
{
	int	pos;

	pos = line->cpos;
	line->cpos -= count;
	if (line->cpos < 0)
		line->cpos = 0;
	str_remove(line->str, line->cpos, pos - line->cpos);
}

static void	clear_line(t_line *line)
{
	ft_bzero(line->str->s, line->str->len);
	line->str->len = 0;
	line->cpos = 0;
}

void	vi_delete_to_motion(t_line *line)
{
	t_line	*new_line;
	int		i;

	if (line != g_line)
		return ;
	new_line = duplicate_line(line);
	vi_input_one(new_line);
	if (new_line->action == vi_delete_to_motion)
		clear_line(line);
	if (new_line->action == reset_line)
		reset_line(line);
	if (is_vi_motion(new_line->action))
	{
		i = (ignore_arg(new_line->action) ? line->arg - 2 : -1);
		while (++i < line->arg)
			if (new_line->cpos < line->cpos)
				delete_left(line, line->cpos - new_line->cpos);
			else if (new_line->cpos > line->cpos)
				delete_right(line, new_line->cpos - line->cpos);
			else if (new_line->action == end_of_line)
				delete_right(line, 1);
	}
	line->vi_mode = VI_INSERT;
	free_line(new_line);
}
