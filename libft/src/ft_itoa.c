/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelisan <gmelisan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 00:32:54 by gmelisan          #+#    #+#             */
/*   Updated: 2019/02/11 05:43:49 by gmelisan         ###   ########.fr       */
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

static void		ft_strrev(char *str)
{
	size_t	i;
	size_t	len;
	char	temp;

	len = ft_strlen(str);
	i = 0;
	while (i < len / 2)
	{
		temp = str[i];
		str[i] = str[len - 1 - i];
		str[len - 1 - i] = temp;
		i++;
	}
}

char			*ft_itoa(int n)
{
	char	*res;
	int		i;
	t_uint	un;
	int		digits;

	un = get_abs(n);
	digits = count_digits(un);
	res = (char *)malloc(sizeof(char) * (digits + (n < 0 ? 1 : 0) + 1));
	if (!res)
		return (NULL);
	i = 0;
	if (un == 0)
		res[i++] = '0';
	while (un)
	{
		res[i] = (un % 10) + '0';
		un = un / 10;
		i++;
	}
	if (n < 0)
		res[i++] = '-';
	res[i] = '\0';
	ft_strrev(res);
	return (res);
}
