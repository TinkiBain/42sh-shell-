/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vi_yank_to_motion.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelisan </var/spool/mail/vladimir>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/16 04:12:30 by gmelisan          #+#    #+#             */
/*   Updated: 2019/08/16 04:16:44 by gmelisan         ###   ########.fr       */
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

static void	yank_right(t_line *line, int count, int ignore)
{
	str_delete(&line->kill_buffer);
	if (!ignore)
		count *= line->arg;
	if (count > (int)line->str->len - line->cpos)
		count = line->str->len - line->cpos;
	line->kill_buffer = str_xsubstring(*line->str, line->cpos, count);
}

static void	yank_left(t_line *line, int count, int ignore)
{
	str_delete(&line->kill_buffer);
	if (!ignore)
		count *= line->arg;
	if (count > line->cpos)
		count = line->cpos;
	line->kill_buffer = str_xsubstring(*line->str, line->cpos - count, count);
}


static void	yank_all(t_line *line)
{
	str_delete(&line->kill_buffer);
	line->kill_buffer = str_xsubstring(*line->str, 0, line->str->len);
}

void		vi_yank_to_motion(t_line *line)
{
	t_line	*new_line;
	int		ignore;

	if (line != g_line)
		return ;
	new_line = duplicate_line(line);
	vi_input_one(new_line);
	if (new_line->action == vi_yank_to_motion)
		yank_all(line);
	if (new_line->action == reset_line)
		reset_line(line);
	if (is_vi_motion(new_line->action))
	{
		ignore = ignore_arg(new_line->action);
		if (new_line->cpos < line->cpos)
			yank_left(line, line->cpos - new_line->cpos, ignore);
		else if (new_line->cpos > line->cpos)
			yank_right(line, new_line->cpos - line->cpos, ignore);
	}
	free_line(new_line);
}
