/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   possible_variable_completions.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelisan <gmelisan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/13 07:41:54 by gmelisan          #+#    #+#             */
/*   Updated: 2019/08/19 08:14:54 by gmelisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "actions.h"

void			possible_variable_completions(t_line *line)
{
	t_string	query;
	char		**vars;
	int			n;
	int			start;

	query = get_variable_query(line, &start);
	get_variables(query, &vars, &n);
	if (n != 1)
		show_completions(vars, n);
	str_delete(&query);
}
