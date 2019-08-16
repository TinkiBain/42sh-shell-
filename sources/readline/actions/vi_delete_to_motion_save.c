/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vi_delete_to_motion_save.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelisan </var/spool/mail/vladimir>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/15 12:49:22 by gmelisan          #+#    #+#             */
/*   Updated: 2019/08/16 03:34:45 by gmelisan         ###   ########.fr       */
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

static void	delete_right_save(t_line *line, int count, int ignore)
{
	str_delete(&line->kill_buffer);
	if (!ignore)
		count *= line->arg;
	if (count > (int)line->str->len - line->cpos)
		count = line->str->len - line->cpos;
	line->kill_buffer = str_xsubstring(*line->str, line->cpos, count);
	str_remove(line->str, line->cpos, count);
}

static void	delete_left_save(t_line *line, int count, int ignore)
{
	str_delete(&line->kill_buffer);
	if (!ignore)
		count *= line->arg;
	if (count > line->cpos)
		count = line->cpos;
	line->kill_buffer = str_xsubstring(*line->str, line->cpos - count, count);
	str_remove(line->str, line->cpos - count, count);
	line->cpos -= count;
}


static void	delete_all_save(t_line *line)
{
	str_delete(&line->kill_buffer);
	line->kill_buffer = str_xsubstring(*line->str, 0, line->str->len);
	ft_bzero(line->str->s, line->str->len);
	line->str->len = 0;
	line->cpos = 0;
}

void		vi_delete_to_motion_save(t_line *line)
{
	t_line	*new_line;
	int		ignore;

	if (line != g_line)
		return ;
	new_line = duplicate_line(line);
	vi_input_one(new_line);
	if (new_line->action == vi_delete_to_motion_save)
		delete_all_save(line);
	if (new_line->action == reset_line)
		reset_line(line);
	if (is_vi_motion(new_line->action))
	{
		ignore = ignore_arg(new_line->action);
		if (new_line->cpos < line->cpos)
			delete_left_save(line, line->cpos - new_line->cpos, ignore);
		else if (new_line->cpos > line->cpos)
			delete_right_save(line, new_line->cpos - line->cpos, ignore);
	}
	free_line(new_line);
}
