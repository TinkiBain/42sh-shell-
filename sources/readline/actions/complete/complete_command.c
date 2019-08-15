/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complete_command.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelisan </var/spool/mail/vladimir>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/13 07:16:12 by gmelisan          #+#    #+#             */
/*   Updated: 2019/08/15 03:36:09 by gmelisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "actions.h"

t_string		get_command_query(t_line *line, int *start)
{
	t_string	res;
	int			i;
	char		c;

	i = line->cpos - 1;
	while ((c = str_get(*line->str, i)) && !ft_isspace(c)
		   && c != ';' && c != '(')
		i--;
	i++;
	*start = i;
	res = str_xsubstring(*line->str, i, line->cpos - i);
	return (res);
}

void			complete_command(t_line *line)
{
	t_vector	vec;
	t_string	query;
	t_string	found;
	int			start;
	int			unmatch_start;

	query = get_command_query(line, &start);
	vec = get_vec_prog(query);
	found = find_common_part(vec);
	unmatch_start = line->cpos - start;
	if (found.len > 0 && (int)found.len > unmatch_start)
	{
		str_xinsert(line->str, line->cpos,
					found.s + unmatch_start, found.len - unmatch_start);
		line->cpos += found.len - unmatch_start;
	}
	else
		show_completions(vec, NULL);
	vec_delete(&vec, del_str);
	str_delete(&found);
	str_delete(&query);
}
