/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reset_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelisan <gmelisan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/30 16:37:41 by gmelisan          #+#    #+#             */
/*   Updated: 2019/10/11 14:30:58 by gmelisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "actions.h"

void	reset_line(t_line *line)
{
	extern t_line	*g_line;

	if (g_line != line)
		return ;
	line->cpos = line->str->len;
	update_line(line, 0);
}
