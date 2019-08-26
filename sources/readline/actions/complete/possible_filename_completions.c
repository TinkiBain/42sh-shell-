/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   possible_filename_completions.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelisan <gmelisan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/13 07:48:28 by gmelisan          #+#    #+#             */
/*   Updated: 2019/08/27 01:02:38 by gmelisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "actions.h"

void			possible_filename_completions(t_line *line)
{
	t_vector	vec;

	vec = filter_filenames(line);
	if (vec.len != 1)
		show_completions(vec.v, vec.len);
	vec_delete(&vec, del_str);
}
