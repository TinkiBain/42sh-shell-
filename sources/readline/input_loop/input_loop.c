/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_loop.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelisan <gmelisan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 16:40:53 by gmelisan          #+#    #+#             */
/*   Updated: 2019/08/26 15:33:39 by gmelisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "input_loop.h"

/*
** 1 - exit, 0 - continue
*/

int				input_loop(t_line *line)
{
	int		ret;

	if (line->vi_mode)
		ret = vi_input_loop(line);
	else
		ret = em_input_loop(line);
	if (ret < 0)
		g_errno = E_READ;
	history_expand(line);
	if (ret <= 0 && line->oldstr.len == 0)
		return (1);
	return (0);
}
