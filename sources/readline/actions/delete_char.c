/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_char.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelisan <gmelisan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/20 07:11:34 by gmelisan          #+#    #+#             */
/*   Updated: 2019/08/17 17:26:21 by wtalea           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "actions.h"

void	delete_char(t_line *line)
{
	int i;

	i = -1;
	while (++i < line->arg)
		str_remove(line->str, line->cpos, 1);
	push_undo_list(line);
}
