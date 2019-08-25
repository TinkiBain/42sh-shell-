/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forward_char.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelisan <gmelisan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/20 07:15:31 by gmelisan          #+#    #+#             */
/*   Updated: 2019/08/16 03:34:24 by gmelisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "actions.h"

void	forward_char(t_line *line)
{
	int i;

	i = -1;
	while (++i < line->arg)
	{
		if (line->cpos < (int)line->str->len)
			line->cpos++;
	}
}
