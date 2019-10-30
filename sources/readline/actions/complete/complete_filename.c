/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complete_filename.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelisan <gmelisan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/07 21:41:52 by gmelisan          #+#    #+#             */
/*   Updated: 2019/10/30 19:55:21 by gmelisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "actions.h"
#include "del_funcs.h"

static int		get_start(t_line *line)
{
	int		i;
	char	c;

	i = line->cpos - 1;
	while ((c = str_get(*line->str, i))
			&& !complete_isspace_check(*line->str, i) && c != '/')
		i--;
	return (++i);
}

void			complete_filename(t_line *line)
{
	t_vector	vec;
	t_string	found;
	int			start;
	int			unmatch_start;

	vec = filter_filenames(line);
	found = find_common_part(vec.v, vec.len);
	complete_escape(&found);
	start = get_start(line);
	unmatch_start = line->cpos - start;
	if ((found.len > 0 && (int)found.len > unmatch_start) || vec.len == 1)
	{
		str_xinsert(line->str, line->cpos,
					found.s + unmatch_start, found.len - unmatch_start);
		line->cpos += found.len - unmatch_start;
	}
	else
		show_completions(vec.v, vec.len);
	vec_delete(&vec, del_pchar);
	str_delete(&found);
}
