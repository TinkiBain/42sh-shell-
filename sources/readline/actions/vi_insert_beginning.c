/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vi_insert_beginning.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelisan <gmelisan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/05 21:03:02 by gmelisan          #+#    #+#             */
/*   Updated: 2019/08/05 21:05:10 by gmelisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "actions.h"

void	vi_insert_beginning(t_line *line)
{
	line->vi_mode = VI_INSERT;
	vi_beginning_of_line_nonblank(line);
}
