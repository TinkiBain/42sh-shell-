/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   possible_variable_completions.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelisan </var/spool/mail/vladimir>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/13 07:41:54 by gmelisan          #+#    #+#             */
/*   Updated: 2019/08/15 02:52:21 by gmelisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "actions.h"

void			possible_variable_completions(t_line *line)
{
	t_string	query;
	int			start;
	t_vector	vec;

	query = get_variable_query(line, &start);
	vec = get_variables(query);
	if (vec.len != 1)
		show_completions(vec, NULL);
	vec_delete(&vec, del_str);
	str_delete(&query);
}
