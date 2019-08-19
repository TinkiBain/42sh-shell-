/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   possible_command_completions.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelisan </var/spool/mail/vladimir>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/13 07:48:10 by gmelisan          #+#    #+#             */
/*   Updated: 2019/08/19 07:30:56 by gmelisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "actions.h"

void			possible_command_completions(t_line *line)
{
	t_string	query;
	int			start;
	t_vector	vec;

	query = get_command_query(line, &start);
	vec = get_vec_prog(query);
	if (vec.len != 1)
		show_completions_old(vec, NULL);
	vec_delete(&vec, del_str);
	str_delete(&query);
}
