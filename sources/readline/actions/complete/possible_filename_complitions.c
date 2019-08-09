/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   possible_filename_complitions.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelisan <gmelisan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/07 21:33:26 by gmelisan          #+#    #+#             */
/*   Updated: 2019/08/09 05:46:49 by gmelisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "actions.h"

static void		del(void *s)
{
	str_delete(s);
}

void			possible_filename_completions(t_line *line)
{
	t_vector	vec;

	vec = get_filenames(line, NULL);
	if (vec.len != 1)
	{
		show_completions(vec);
		line->complete_fail = 1;
	}
	else
		line->complete_fail = 0;
	vec_delete(&vec, del);
}
