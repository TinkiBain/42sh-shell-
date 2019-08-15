/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   possible_filename_completions.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelisan </var/spool/mail/vladimir>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/13 07:48:28 by gmelisan          #+#    #+#             */
/*   Updated: 2019/08/15 02:51:56 by gmelisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "actions.h"

void			possible_filename_completions(t_line *line)
{
	t_vector	vec;

	vec = get_filenames(line);
	if (vec.len != 1)
		show_completions(vec, NULL);
	vec_delete(&vec, del_str);
}
