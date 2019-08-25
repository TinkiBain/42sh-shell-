/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vi_goto_char.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelisan <gmelisan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/15 10:11:39 by gmelisan          #+#    #+#             */
/*   Updated: 2019/08/15 10:16:16 by gmelisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "actions.h"

void	vi_goto_char(t_line *line)
{
	if (line->arg < 1)
		line->arg = 1;
	if (line->arg > (int)line->str->len)
		line->arg = line->str->len;
	line->cpos = line->arg - 1;
}
