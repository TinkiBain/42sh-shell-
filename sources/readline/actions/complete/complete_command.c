/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complete_command.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelisan </var/spool/mail/vladimir>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/13 07:16:12 by gmelisan          #+#    #+#             */
/*   Updated: 2019/08/13 08:26:37 by gmelisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "actions.h"

t_string		get_command_query(t_line *line)
{
	t_string	res;
	int			i;
	char		c;

	i = line->cpos - 1;
	while ((c = str_get(*line->str, i)) && !ft_isspace(c) && c != ';')
		i--;
	i++;
	res = str_xsubstring(*line->str, i, line->cpos - i);
	return (res);
}

static int		get_start(t_line *line)
{
	int		i;
	char	c;

	i = line->cpos - 1;
	while ((c = str_get(*line->str, i)) && !ft_isspace(c) && c != ';')
		i--;
	return (++i);
}

void			complete_command(t_line *line)
{
	t_vector	vec;
	t_string	query;
	t_string	found;
	int			start;
	int			unmatch_start;

	query = get_command_query(line);
	vec = get_vec_prog(query.s);
	found = find_common_part(vec);
	if (line->complete_fail)
	{
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
	free(vec.v);
	str_delete(&found);
	str_delete(&query);
}
