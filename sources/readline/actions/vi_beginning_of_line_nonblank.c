/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vi_beginning_of_line_nonblank.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelisan <gmelisan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/05 20:53:28 by gmelisan          #+#    #+#             */
/*   Updated: 2019/08/05 21:13:52 by gmelisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "actions.h"

void vi_beginning_of_line_nonblank(t_line *line)
{
	line->cpos = 0;
	while (ft_isspace(str_get(*line->str, line->cpos)))
		line->cpos++;
}
