/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complete_command_option.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelisan <gmelisan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 23:05:28 by gmelisan          #+#    #+#             */
/*   Updated: 2019/09/05 23:05:35 by gmelisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "actions.h"
#include "hash.h"

t_string	get_command_name(t_line *line, int *start, t_string *query)
{
	t_string	res;
	int			from;
	int			i;
	char		c;

	*query = str_xcreate(0);
	i = line->cpos - 1;
	while ((c = str_get(*line->str, i)) && !ft_isspace(c))
	{
		str_xaddfront(query, &c, 1);
		i--;
	}
	*start = i + 1;
	while ((c = str_get(*line->str, i)) && ft_isspace(c))
		i--;
	from = i;
	while ((c = str_get(*line->str, from)) && !ft_isspace(c))
		from--;
	from++;
	res = str_xsubstring(*line->str, from, i + 1 - from);
	return (res);
}

static void	cut_by_space(t_string *str)
{
	int	i;

	i = 0;
	while (str_get(*str, i) && !ft_isspace(str_get(*str, i)))
		i++;
	str_remove(str, i, str->len - i);
	str_xaddback(str, " ", 1);
}

/* 
** data[0] - n (size of arr)
** data[1] - start (pos in line where query starts)
** data[2] - unmatch_start (pos in line where first unmatch char appears)
*/

void	complete_command_option(t_line *line)
{
	t_string		query;
	t_string		command;
	t_string		found;
	char			**arr;
	int				data[3];

	command = get_command_name(line, &data[1], &query);
	filter_command_options(command, query, &arr, &data[0]);
	found = find_common_part(arr, data[0]);
	data[2] = line->cpos - data[1];
	if ((found.len > 0 && (int)found.len > data[2]) || data[0] == 1)
	{
		if (data[0] == 1)
			cut_by_space(&found);
		str_xinsert(line->str, line->cpos,
					found.s + data[2], found.len - data[2]);
		line->cpos += found.len - data[2];
	}
	else
		show_completions(arr, data[0]);
	str_delete(&command);
	str_delete(&found);
	str_delete(&query);
}
