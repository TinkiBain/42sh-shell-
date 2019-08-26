/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   possible_command_completions.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelisan <gmelisan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/13 07:48:10 by gmelisan          #+#    #+#             */
/*   Updated: 2019/08/27 01:04:04 by gmelisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "actions.h"

void			possible_command_completions(t_line *line)
{
	t_string	query;
	char		**cmds;
	int			n;
	int			start;

	query = get_command_query(line, &start);
	filter_commands(query, &cmds, &n);
	if (n != 1)
		show_completions(cmds, n);
	str_delete(&query);
}
