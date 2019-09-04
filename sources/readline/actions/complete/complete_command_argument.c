/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complete_command_argument.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelisan <gmelisan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 14:36:06 by gmelisan          #+#    #+#             */
/*   Updated: 2019/09/04 19:19:01 by gmelisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "actions.h"
#include "hash.h"

t_string	get_command_name(t_line *line, int *start)
{
	t_string	res;
	int			from;
	int			i;
	char		c;

	i = line->cpos - 1;
	while ((c = str_get(*line->str, i)) && !ft_isspace(c))
		i--;
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

void	complete_command_argument(t_line *line)
{
	t_string		query;
	t_string		found;
	int				start;
	int				unmatch_start;
	struct s_var	cmdargs;
	
	query = get_command_name(line, &start);
	cmdargs.arr = hash_get_flags(query.s);
	cmdargs.n = 0;
	while (cmdargs.arr[cmdargs.n])
		cmdargs.n++;
	found = find_common_part(cmdargs.arr, cmdargs.n);
	unmatch_start = line->cpos - start;
	if ((found.len > 0 && (int)found.len > unmatch_start) || cmdargs.n == 1)
	{
		if (cmdargs.n == 1)
			str_xaddback(&found, " ", 1);
		str_xinsert(line->str, line->cpos,
					found.s + unmatch_start, found.len - unmatch_start);
		line->cpos += found.len - unmatch_start;
	}
	else
		show_one_column(cmdargs.arr, cmdargs.n);
	str_delete(&found);
	str_delete(&query);
}
