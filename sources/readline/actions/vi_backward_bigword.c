/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vi_backward_bigword.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelisan <gmelisan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/15 10:32:59 by gmelisan          #+#    #+#             */
/*   Updated: 2019/08/25 18:45:25 by gmelisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "actions.h"

static int	is_delim(char c)
{
	if (ft_isspace(c))
		return (1);
	return (0);
}

void		vi_backward_bigword(t_line *line)
{
	int i;
	int j;

	j = -1;
	while (++j < line->arg)
	{
		i = line->cpos;
		if (is_delim(str_get(*line->str, i - 1)))
			i--;
		while (is_delim(str_get(*line->str, i)) && i >= 0)
			i--;
		while (!is_delim(str_get(*line->str, i)) && i >= 0)
			i--;
		i++;
		line->cpos = i;
	}
}
