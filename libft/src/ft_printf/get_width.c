/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_width.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelisan <gmelisan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/28 14:47:57 by gmelisan          #+#    #+#             */
/*   Updated: 2019/01/28 14:48:58 by gmelisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	get_width(va_list ap, t_conversion *conv, const char *format, int *p_i)
{
	int i;
	int width;

	i = *p_i;
	conv->width = 0;
	if (format[i] == '*')
	{
		width = va_arg(ap, int);
		conv->width = width < 0 ? -width : width;
		conv->flags.minus = width < 0 ? 1 : conv->flags.minus;
		i++;
	}
	else
		while (ft_isdigit(format[i]))
		{
			conv->width = conv->width * 10 + (format[i] - '0');
			i++;
		}
	*p_i = i;
}
