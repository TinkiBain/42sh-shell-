/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backward_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelisan <gmelisan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/20 07:16:01 by gmelisan          #+#    #+#             */
/*   Updated: 2019/08/15 06:24:12 by gmelisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "actions.h"

void	backward_char(t_line *line)
{
	int	i;

	i = -1;
	while (++i < line->arg)
		if (line->cpos > 0)
			line->cpos--;
}
