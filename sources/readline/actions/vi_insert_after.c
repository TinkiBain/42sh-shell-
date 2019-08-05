/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vi_insert_after.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelisan <gmelisan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/05 21:00:44 by gmelisan          #+#    #+#             */
/*   Updated: 2019/08/05 21:00:48 by gmelisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "actions.h"

void	vi_insert_after(t_line *line)
{
	line->vi_mode = VI_INSERT;
	forward_char(line);
	if (line->cpos == (int)line->str->len - 1)
		line->cpos++;
}
