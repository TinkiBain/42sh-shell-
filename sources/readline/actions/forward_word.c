/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forward_word.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelisan </var/spool/mail/vladimir>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/20 07:17:13 by gmelisan          #+#    #+#             */
/*   Updated: 2019/07/20 07:18:19 by gmelisan         ###   ########.fr       */
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

	i = line->cpos;
	while (is_delim(str_get(*line->str, i)) && i <= (int)line->str->len)
		i++;
	while (!is_delim(str_get(*line->str, i)) && i <= (int)line->str->len)
		i++;
	if (i > (int)line->str->len)
		i = line->str->len;
	line->cpos = i;
}
