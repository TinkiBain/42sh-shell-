/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vi_delete_to_motion.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelisan <gmelisan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/15 05:07:21 by gmelisan          #+#    #+#             */
/*   Updated: 2019/10/11 14:28:16 by gmelisan         ###   ########.fr       */
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

static void	delete_right(t_line *line, int count, int ignore)
{
	if (!ignore)
		count *= line->arg;
	if (count > (int)line->str->len - line->cpos)
		count = line->str->len - line->cpos;
	str_remove(line->str, line->cpos, count);
}

static void	delete_left(t_line *line, int count, int ignore)
{
	if (!ignore)
		count *= line->arg;
	if (count > line->cpos)
		count = line->cpos;
	str_remove(line->str, line->cpos - count, count);
	line->cpos -= count;
}

void		vi_delete_to_motion(t_line *line)
{
	extern t_line	*g_line;
	t_line			*new_line;
	int				ignore;

	if (line != g_line)
		return ;
	new_line = duplicate_line(line);
	vi_input_one(new_line);
	if (new_line->action == vi_delete_to_motion)
		vi_clear_line(line);
	if (new_line->action == reset_line)
		reset_line(line);
	if (is_vi_motion(new_line->action))
	{
		ignore = ignore_arg(new_line->action);
		if (new_line->cpos < line->cpos)
			delete_left(line, line->cpos - new_line->cpos, ignore);
		else if (new_line->cpos > line->cpos)
			delete_right(line, new_line->cpos - line->cpos, ignore);
	}
	if (new_line->action != vi_ignore)
		line->vi_mode = VI_INSERT;
	free_line(new_line);
}
