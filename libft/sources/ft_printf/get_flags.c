/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_flags.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelisan <gmelisan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/28 14:47:27 by gmelisan          #+#    #+#             */
/*   Updated: 2019/01/29 17:53:53 by gmelisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			get_flags(t_conversion *conv, const char *format, int *p_i)
{
	int i;

	i = *p_i;
	if (format[i] == '#')
		conv->flags.hash = 1;
	if (format[i] == '0')
		conv->flags.zero = 1;
	if (format[i] == '-')
		conv->flags.minus = 1;
	if (format[i] == ' ')
		conv->flags.space = 1;
	if (format[i] == '+')
		conv->flags.plus = 1;
	i++;
	*p_i = i;
}
