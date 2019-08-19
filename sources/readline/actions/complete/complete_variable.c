/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complete_variable.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelisan </var/spool/mail/vladimir>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/13 07:32:18 by gmelisan          #+#    #+#             */
/*   Updated: 2019/08/19 17:17:06 by gmelisan         ###   ########.fr       */
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

static void	add_space(t_string *str, int one, int add_brace)
{
	if (one && add_brace)
		str_xaddback(str, "} ", 2);
	else if (one)
		str_xaddback(str, " ", 1);
}

void		complete_variable(t_line *line)
{
	t_string	query;
	t_string	found;
	int			start;
	int			unmatch_start;
	char		**vars;
	int			n;

	query = get_variable_query(line, &start);
	get_variables(query, &vars, &n);
	found = find_common_part(vars, n);
	unmatch_start = line->cpos - start;
	if (found.len > 0 && (int)found.len > unmatch_start)
	{
		add_space(&found, n == 1, str_get(*line->str, start - 1) == '{');
		str_xinsert(line->str, line->cpos,
					found.s + unmatch_start, found.len - unmatch_start);
		line->cpos += found.len - unmatch_start;
	}
	else if (str_get(*line->str, start - 1) == '{')
		show_completions(vars, n);
	else
		show_completions(vars, n);
	str_delete(&found);
	str_delete(&query);
}
