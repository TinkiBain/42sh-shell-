/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complete_command.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelisan </var/spool/mail/vladimir>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/13 07:16:12 by gmelisan          #+#    #+#             */
/*   Updated: 2019/08/19 19:08:44 by gmelisan         ###   ########.fr       */
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
	t_string		query;
	t_string		found;
	int				start;
	int				unmatch_start;
	struct s_var	cmds;

	query = get_command_query(line, &start);
	get_commands(query, &cmds.arr, &cmds.n);
	found = find_common_part(cmds.arr, cmds.n);
	unmatch_start = line->cpos - start;
	if ((found.len > 0 && (int)found.len > unmatch_start) || cmds.n == 1)
	{
		if (cmds.n == 1)
			str_xaddback(&found, " ", 1);
		str_xinsert(line->str, line->cpos,
					found.s + unmatch_start, found.len - unmatch_start);
		line->cpos += found.len - unmatch_start;
	}
	else
		show_completions(cmds.arr, cmds.n);
	str_delete(&found);
	str_delete(&query);
}
