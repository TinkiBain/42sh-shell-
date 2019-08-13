/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   possible_command_completions.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelisan </var/spool/mail/vladimir>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/13 07:48:10 by gmelisan          #+#    #+#             */
/*   Updated: 2019/08/13 08:01:03 by gmelisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "actions.h"

void			possible_command_completions(t_line *line)
{
	t_string	query;
	t_vector	vec;

	query = get_command_query(line);
	vec = get_vec_prog(query.s);
	if (vec.len != 1)
		show_completions(vec);
	free(vec.v);
	str_delete(&query);
}
