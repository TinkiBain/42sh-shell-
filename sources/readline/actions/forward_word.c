/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forward_word.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelisan <gmelisan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/20 07:17:13 by gmelisan          #+#    #+#             */
/*   Updated: 2019/08/15 06:30:04 by gmelisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "actions.h"

static int	is_delim(char c)
{
	if (ft_isalnum(c))
		return (0);
	return (1);
}

void		forward_word(t_line *line)
{
	int i;
	int j;

	j = -1;
	while (++j < line->arg)
	{
		i = line->cpos;
		while (is_delim(str_get(*line->str, i)) && i <= (int)line->str->len)
			i++;
		while (!is_delim(str_get(*line->str, i)) && i <= (int)line->str->len)
			i++;
		if (i > (int)line->str->len)
			i = line->str->len;
		line->cpos = i;
	}
}
