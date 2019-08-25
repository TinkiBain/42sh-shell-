/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complete_variable.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelisan <gmelisan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/13 07:32:18 by gmelisan          #+#    #+#             */
/*   Updated: 2019/08/25 18:14:00 by gmelisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "actions.h"

t_string		get_variable_query(t_line *line, int *start)
{
	t_string	res;
	int			i;
	char		c;

	i = line->cpos - 1;
	while ((c = str_get(*line->str, i)) && c != '$' && c != '{')
		i--;
	i++;
	*start = i;
	res = str_xsubstring(*line->str, i, line->cpos - i);
	return (res);
}

static void		add_space(t_string *str, int one, int add_brace)
{
	if (one && add_brace)
		str_xaddback(str, "} ", 2);
	else if (one)
		str_xaddback(str, " ", 1);
}

void			complete_variable(t_line *line)
{
	t_string		query;
	t_string		found;
	int				start;
	int				unmatch_start;
	struct s_var	vars;

	query = get_variable_query(line, &start);
	get_variables(query, &vars.arr, &vars.n);
	found = find_common_part(vars.arr, vars.n);
	unmatch_start = line->cpos - start;
	if ((found.len > 0 && (int)found.len > unmatch_start) || vars.n == 1)
	{
		add_space(&found, vars.n == 1, str_get(*line->str, start - 1) == '{');
		str_xinsert(line->str, line->cpos,
					found.s + unmatch_start, found.len - unmatch_start);
		line->cpos += found.len - unmatch_start;
	}
	else if (str_get(*line->str, start - 1) == '{')
		show_completions(vars.arr, vars.n);
	else
		show_completions(vars.arr, vars.n);
	str_delete(&found);
	str_delete(&query);
}
