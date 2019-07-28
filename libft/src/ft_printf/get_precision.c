/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_precision.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelisan <gmelisan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/28 14:49:31 by gmelisan          #+#    #+#             */
/*   Updated: 2019/01/28 14:50:34 by gmelisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	get_precision(va_list ap, t_conversion *conv, const char *format,
						int *p_i)
{
	int		i;
	int		prec;

	i = *p_i + 1;
	conv->prec_set = 1;
	conv->precision = 0;
	if (format[i] == '*')
	{
		prec = va_arg(ap, int);
		if (prec < 0)
			conv->prec_set = 0;
		else
			conv->precision = prec;
		i++;
	}
	else
		while (ft_isdigit(format[i]))
		{
			conv->precision = conv->precision * 10 + (format[i] - '0');
			i++;
		}
	*p_i = i;
}
