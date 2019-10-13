/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vi_command.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelisan <gmelisan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/05 21:02:11 by gmelisan          #+#    #+#             */
/*   Updated: 2019/10/13 12:39:46 by gmelisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "actions.h"

void		vi_command(t_line *line)
{
	line->vi_mode = VI_COMMAND;
	line->overwrite_mode = 0;
	backward_char(line);
	push_undo_list(line);
}
