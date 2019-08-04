/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backward_word.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelisan </var/spool/mail/vladimir>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/20 07:17:32 by gmelisan          #+#    #+#             */
/*   Updated: 2019/07/20 07:18:07 by gmelisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "actions.h"

static int	is_delim(char c)
{
	if (ft_isalnum(c))
		return (0);
	return (1);
}

void		backward_word(t_line *line)
{
	int i;

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
