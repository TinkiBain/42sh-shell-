/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   number_to_string.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelisan <gmelisan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/28 15:11:43 by gmelisan          #+#    #+#             */
/*   Updated: 2019/01/29 18:00:33 by gmelisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static t_uint	count_digits(t_ullint n, int base)
{
	t_uint res;

	res = 1;
	while ((n = n / base))
		res++;
	return (res);
}

static t_ullint	absolute_value(t_llint n)
{
	t_ullint un;

	if (n >= 0)
		un = (t_ullint)n;
	else
	{
		n = (n + 1) * (-1);
		un = (t_ullint)n;
		un++;
	}
	return (un);
}

static char		int2char(int n, int flag_bigsym)
{
	if (n > 9)
		return (n - 10 + (flag_bigsym ? 'A' : 'a'));
	return (n + '0');
}

int				get_base(char c)
{
	if (c == 'x' || c == 'X' || c == 'p')
		return (16);
	if (c == 'o' || c == 'O')
		return (8);
	if (c == 'b')
		return (2);
	return (10);
}

char			*number_to_string(t_llint n, t_conversion *conv,
									int flag_unsigned)
{
	t_uint		digits;
	int			i;
	t_ullint	un;
	int			base;
	char		*str;

	un = flag_unsigned ? (t_ullint)n : absolute_value(n);
	base = get_base(conv->type);
	digits = count_digits(un, base);
	str = ft_strnew(digits);
	i = digits - 1;
	if (un == 0)
		str[i] = '0';
	while (un)
	{
		str[i] = int2char(un % base, (conv->type == 'X' ? 1 : 0));
		un = un / base;
		i--;
	}
	return (str);
}
