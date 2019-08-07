/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complete_filename.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelisan <gmelisan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/07 21:41:52 by gmelisan          #+#    #+#             */
/*   Updated: 2019/08/07 22:15:40 by gmelisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "actions.h"

static void		del(void *s)
{
	str_delete(s);
}

void	complete_filename(t_line *line)
{
	t_vector	vec;
	t_string	*found;
	int			start;

	vec = get_filenames(line, &start);
	if (vec.len == 1)
	{
		found = vec_get(vec, 0);
		ft_bzero(line->str->s + start, line->str->len - start);
		line->str->len = start;
		str_xaddback(line->str, found->s, found->len);
		line->cpos = line->str->len;
	}
	vec_delete(&vec, del);
}
