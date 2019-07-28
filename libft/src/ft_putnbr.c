/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelisan <gmelisan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 02:43:34 by gmelisan          #+#    #+#             */
/*   Updated: 2018/11/27 17:21:36 by gmelisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		count_digits(t_uint n)
{
	int ret;

	if (n == 0)
		return (1);
	ret = 0;
	while (n)
	{
		n = n / 10;
		ret++;
	}
	return (ret);
}

static t_uint	get_abs(int n)
{
	t_uint un;

	if (n >= 0)
		un = (t_uint)n;
	else
	{
		n = (n + 1) * (-1);
		un = (t_uint)n;
		un++;
	}
	return (un);
}

static int		power10(t_uint n)
{
	if (n == 0)
		return (1);
	if (n == 1)
		return (10);
	if (n == 2)
		return (100);
	if (n == 3)
		return (1000);
	if (n == 4)
		return (10000);
	if (n == 5)
		return (100000);
	if (n == 6)
		return (1000000);
	if (n == 7)
		return (10000000);
	if (n == 8)
		return (100000000);
	if (n == 9)
		return (1000000000);
	return (1);
}

void			ft_putnbr(int n)
{
	t_uint	un;
	t_uint	p;
	int		digits;

	if (n < 0)
		ft_putchar('-');
	un = get_abs(n);
	digits = count_digits(un);
	p = power10(digits - 1);
	if (un == 0)
		ft_putchar('0');
	else
		while (digits != 0)
		{
			ft_putchar(un / p + '0');
			un = un % p;
			p = p / 10;
			digits--;
		}
}
