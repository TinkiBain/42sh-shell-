/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vi_forward_word_start.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelisan </var/spool/mail/vladimir>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/15 11:08:55 by gmelisan          #+#    #+#             */
/*   Updated: 2019/08/15 11:22:39 by gmelisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "actions.h"

static int	is_delim(char c)
{
	if (ft_isalnum(c))
		return (0);
	return (1);
}

void	vi_forward_word_start(t_line *line)
{
	int i;
	int j;

	j = -1;
	while (++j < line->arg)
	{
		i = line->cpos;
		while (!is_delim(str_get(*line->str, i)) && i <= (int)line->str->len)
			i++;
		while (is_delim(str_get(*line->str, i)) && i <= (int)line->str->len)
			i++;
		if (i > (int)line->str->len)
			i = line->str->len;
		line->cpos = i;
	}
}
