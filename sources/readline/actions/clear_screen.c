/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_screen.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelisan <gmelisan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/20 07:19:19 by gmelisan          #+#    #+#             */
/*   Updated: 2019/10/30 20:26:25 by gmelisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "actions.h"
#include "utils.h"

void		clear_screen(t_line *line)
{
	if (line)
	{
		tputs(g_cap.clear_all, get_screen_height(), ft_putint);
		update_line(NULL, 0);
	}
}
