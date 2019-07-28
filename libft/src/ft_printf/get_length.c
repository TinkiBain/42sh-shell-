/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_length.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelisan <gmelisan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/28 14:51:21 by gmelisan          #+#    #+#             */
/*   Updated: 2019/01/31 17:34:28 by gmelisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static enum e_length	check_length(t_conversion *conv, enum e_length l)
{
	if (l > conv->length)
		return (l);
	return (conv->length);
}

void					get_length(t_conversion *conv, const char *format,
									int *p_i)
{
	int i;

	i = *p_i;
	if (format[i] == 'L')
		conv->length = check_length(conv, L_LB);
	else if (format[i] == 'h' && format[i + 1] != 'h')
		conv->length = check_length(conv, L_H);
	else if (format[i] == 'h' && format[i + 1] == 'h')
		conv->length = check_length(conv, L_HH);
	else if (format[i] == 'l' && format[i + 1] != 'l')
		conv->length = check_length(conv, L_L);
	else if (format[i] == 'l' && format[i + 1] == 'l')
		conv->length = check_length(conv, L_LL);
	else if (format[i] == 'j')
		conv->length = check_length(conv, L_J);
	else if (format[i] == 'z')
		conv->length = check_length(conv, L_Z);
	if ((format[i] == 'h' && format[i + 1] == 'h') ||
		(format[i] == 'l' && format[i + 1] == 'l'))
		i += 2;
	else
		i += 1;
	*p_i = i;
}
