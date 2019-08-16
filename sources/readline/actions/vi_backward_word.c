/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vi_backward_word.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelisan </var/spool/mail/vladimir>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/15 10:48:27 by gmelisan          #+#    #+#             */
/*   Updated: 2019/08/15 10:53:40 by gmelisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "actions.h"

static int	is_delim(char c)
{
	if (ft_isalnum(c))
		return (0);
	return (1);
}

void		vi_backward_word(t_line *line)
{
	int i;
	int j;

	j= -1;
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
