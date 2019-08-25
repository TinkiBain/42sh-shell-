/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   yank.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelisan <gmelisan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/20 08:05:32 by gmelisan          #+#    #+#             */
/*   Updated: 2019/07/20 08:30:59 by gmelisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "actions.h"

void	yank(t_line *line)
{
	str_xinsert(line->str, line->cpos, line->kill_buffer.s,
													line->kill_buffer.len);
	line->cpos += line->kill_buffer.len;
}
