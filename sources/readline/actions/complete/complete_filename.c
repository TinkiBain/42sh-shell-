/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complete_filename.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelisan <gmelisan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/07 21:41:52 by gmelisan          #+#    #+#             */
/*   Updated: 2019/08/13 08:27:42 by gmelisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "actions.h"

static int		get_start(t_line *line)
{
	int		i;
	char	c;

	i = line->cpos - 1;
	while ((c = str_get(*line->str, i)) && !ft_isspace(c) && c != '/')
		i--;
	return (++i);
}

void			complete_filename(t_line *line)
{
	t_vector	vec;
	t_string	found;
	int			start;
	int			unmatch_start;

	vec = get_filenames(line);
	found = find_common_part(vec);
	if (line->complete_fail)
	{
		/* possible_filename_completions(line); */
		show_completions(vec);
		line->complete_fail = 0;
	}
	else if (found.len > 0)
	{
		line->complete_fail = (vec.len == 1 ? 0 : 1);
		start = get_start(line);
		unmatch_start = line->cpos - start;
		str_xinsert(line->str, line->cpos,
					found.s + unmatch_start, found.len - unmatch_start);
		line->cpos += found.len - unmatch_start;
	}
	else
		line->complete_fail = 1;
	vec_delete(&vec, del_str);
	str_delete(&found);
}

/* Pochemu tak slozhno blyat */

void			_complete_filename(t_line *line)
{
	t_vector	vec;
	t_string	found;
	int			start;
	int			unmatch_start;

	vec = get_filenames(line);
	found = find_common_part(vec);
	if (line->complete_fail)
		possible_filename_completions(line);
	if (found.len > 0)
	{
		if (vec.len == 1)
			line->complete_fail = 0;
		else
			line->complete_fail = 1;
		start = get_start(line);
		unmatch_start = line->cpos - start;
		str_xinsert(line->str, line->cpos,
					found.s + unmatch_start, found.len - unmatch_start);
		line->cpos += found.len - unmatch_start;
	}
	else
		line->complete_fail = 1;
	vec_delete(&vec, del_str);
	str_delete(&found);
}
