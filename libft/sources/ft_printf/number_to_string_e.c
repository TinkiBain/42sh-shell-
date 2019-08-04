/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   number_to_string_e.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelisan <gmelisan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/28 16:33:04 by gmelisan          #+#    #+#             */
/*   Updated: 2019/01/30 15:31:33 by gmelisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** 123.456 (double) -> 1.234566 (double)
** 0.00123 (double) -> 1.23 (double)
*/

static void			normalize_e(long double *n, int *digits)
{
	if (*n >= 1)
		normalize_f(n, digits);
	else
	{
		*digits = -1;
		while (*n < 1)
		{
			*n = *n * 10;
			(*digits)++;
		}
		*digits = -(*digits);
	}
}

/*
** 1.23456 (double) -> 1.23456 (char *)
*/

static void			shift_point_1(long double n, char *str, int prec)
{
	int				i;
	long double		sub;
	int				d;

	i = 0;
	d = (int)n;
	str[i++] = d + '0';
	str[i++] = '.';
	sub = (long double)d;
	while (i < prec + 2 + 1)
	{
		n = n * 10;
		sub = sub * 10;
		d = n - sub;
		sub += d;
		str[i++] = d + '0';
	}
}

/*
** One day I'll get rid of all these reallocs, but not today
*/

static int			add_e(char **str, int len, char e, int exp)
{
	ft_realloc((void **)str, len, len + 5);
	(*str)[len + 0] = e;
	(*str)[len + 1] = (exp >= 0 ? '+' : '-');
	exp = (exp > 0 ? exp : -exp);
	(*str)[len + 2] = exp / 10 + '0';
	(*str)[len + 3] = exp % 10 + '0';
	(*str)[len + 4] = '\0';
	return (len + 4);
}

/*
** n = 123.456
** len = 3(digits) + 1(dot) + precision + 1(for rounding)
*/

void				number_to_string_e(t_conversion *conv, long double n)
{
	int		digits;
	int		len;

	digits = 0;
	if (n < 0)
		n = -n;
	normalize_e(&n, &digits);
	if (conv->prec_set && conv->precision == 0)
		len = 1 + 1 + 1;
	else
		len = 1 + 1 + conv->precision + 1;
	conv->out = ft_strnew(len);
	shift_point_1(n, conv->out, conv->precision);
	round_str(conv->out, len - 1, 0);
	if (conv->prec_set && conv->precision == 0 && !conv->flags.hash)
		add_e(&(conv->out), len - 2, conv->type, digits - 1);
	else
		add_e(&(conv->out), len - 1, conv->type, digits - 1);
}
