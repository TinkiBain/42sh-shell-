/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vi_insert_end.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelisan <gmelisan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/05 21:04:02 by gmelisan          #+#    #+#             */
/*   Updated: 2019/08/05 21:05:43 by gmelisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "actions.h"

void	vi_insert_end(t_line *line)
{
	line->vi_mode = VI_INSERT;
	line->cpos = (int)line->str->len - 1;
	vi_insert_after(line);
}
