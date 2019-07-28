/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   number_to_string_f.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelisan <gmelisan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/28 16:29:19 by gmelisan          #+#    #+#             */
/*   Updated: 2019/01/30 15:24:17 by gmelisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** 123.456 (double) -> 1.234566 (double)
*/

void			normalize_f(long double *n, int *digits)
{
	*digits = 1;
	while (*n >= 10)
	{
		*n = *n / 10;
		(*digits)++;
	}
}

/*
** 1.23456 (double) -> 123.456 (char *)
*/

static void		shift_point(long double n, char *str,
									int len, int digits)
{
	int				i;
	long double		sub;
	int				d;

	i = 0;
	d = (int)n;
	str[i++] = d + '0';
	sub = (long double)d;
	while (i < len)
	{
		if (i == digits)
			str[i++] = '.';
		n = n * 10;
		sub = sub * 10;
		d = n - sub;
		sub += d;
		str[i++] = d + '0';
	}
}

/*
** prec = 2
** 123.456 -> 123.46
** 123.496 -> 123.50
** 123.999 -> 124.00
*/

void			round_str(char *str, int i, int carry)
{
	int prev;

	prev = i - 1;
	if (str[prev] == '.')
		prev--;
	if (prev < 0)
		return ;
	if (str[i] >= '5' || carry)
	{
		if (str[prev] == '9')
		{
			str[prev] = '0';
			round_str(str, prev, 1);
		}
		else
			str[prev]++;
	}
}

void			number_to_string_f(t_conversion *conv, long double n)
{
	int		digits;
	int		len;

	digits = 0;
	if (n < 0)
		n = -n;
	normalize_f(&n, &digits);
	if (conv->prec_set && conv->precision == 0)
		len = digits + 1 + 1;
	else
		len = digits + 1 + conv->precision + 1;
	conv->out = ft_strnew(len);
	shift_point(n, conv->out, len, digits);
	round_str(conv->out, len - 1, 0);
	conv->out[len - 1] = '\0';
	if (conv->prec_set && conv->precision == 0 && !conv->flags.hash)
		conv->out[len - 2] = '\0';
}
