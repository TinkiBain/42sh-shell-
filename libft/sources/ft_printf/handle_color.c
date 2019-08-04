/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_color.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelisan <gmelisan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 17:08:53 by gmelisan          #+#    #+#             */
/*   Updated: 2019/01/29 17:32:05 by gmelisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		handle_color(char *color_before, char *color_after, int size)
{
	if (!color_before)
		return (0);
	ft_bzero(color_after, size);
	if (ft_strequ(color_before, "black"))
		ft_strcpy(color_after, COLOR_BLACK);
	else if (ft_strequ(color_before, "red"))
		ft_strcpy(color_after, COLOR_RED);
	else if (ft_strequ(color_before, "green"))
		ft_strcpy(color_after, COLOR_GREEN);
	else if (ft_strequ(color_before, "yellow"))
		ft_strcpy(color_after, COLOR_YELLOW);
	else if (ft_strequ(color_before, "blue"))
		ft_strcpy(color_after, COLOR_BLUE);
	else if (ft_strequ(color_before, "purple"))
		ft_strcpy(color_after, COLOR_PURPLE);
	else if (ft_strequ(color_before, "cyan"))
		ft_strcpy(color_after, COLOR_CYAN);
	else if (ft_strequ(color_before, "eoc"))
		ft_strcpy(color_after, COLOR_EOC);
	else
		return (0);
	return (1);
}
