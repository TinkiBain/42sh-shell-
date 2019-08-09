/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complete_filename.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelisan <gmelisan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/07 21:41:52 by gmelisan          #+#    #+#             */
/*   Updated: 2019/08/09 05:47:19 by gmelisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "actions.h"

static void		del(void *s)
{
	str_delete(s);
}

static int		get_start(t_line *line)
{
	int		i;
	char	c;

	i = line->cpos - 1;
	while ((c = str_get(*line->str, i)) && !ft_isspace(c) && c != '/')
		i--;
	return (++i);
}

void			complete_filename(t_line *line)
{
	t_vector	vec;
	t_string	*found;
	int			start;

	vec = get_filenames(line, NULL);
	if (vec.len == 1)
	{
		line->complete_fail = 0;
		found = vec_get(vec, 0);
		start = get_start(line);
		ft_bzero(line->str->s + start, line->str->len - start);
		line->str->len = start;
		str_xaddback(line->str, found->s, found->len);
		line->cpos = line->str->len;
	}
	else
		line->complete_fail = 1;
	vec_delete(&vec, del);
}
