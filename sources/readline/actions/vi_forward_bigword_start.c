/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vi_forward_bigword_start.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelisan </var/spool/mail/vladimir>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/15 11:24:02 by gmelisan          #+#    #+#             */
/*   Updated: 2019/08/15 11:24:28 by gmelisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "actions.h"

static int	is_delim(char c)
{
	if (ft_isspace(c))
		return (1);
	return (0);
}

void	vi_forward_bigword_start(t_line *line)
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
