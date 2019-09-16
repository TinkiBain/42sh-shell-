/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_test_int_compare_more_less.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wtalea <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 17:04:56 by wtalea            #+#    #+#             */
/*   Updated: 2019/09/16 14:39:16 by gmelisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_test.h"

int		test_compare_int_less(char *str, char *str2)
{
	long		num[2];

	errno = 0;
	num[0] = 0;
	num[1] = 0;
	if (ft_find_num(str) || ft_find_num(str2))
		return (test_integer_expression((ft_find_num(str)) ? str2 : str));
	num[0] = ft_strtol(str, NULL, 10);
	if (errno)
		return (test_integer_expression(str));
	num[1] = ft_strtol(str2, NULL, 10);
	if (errno)
		return (test_integer_expression(str2));
	if (num[0] != (int)num[0])
		return (test_integer_expression(str));
	if (num[1] != (int)num[1])
		return (test_integer_expression(str2));
	if (num[0] < num[1])
		return (0);
	return (1);
}

int		test_compare_int_more(char *str, char *str2)
{
	long		num[2];

	errno = 0;
	num[0] = 0;
	num[1] = 0;
	if (ft_find_num(str) || ft_find_num(str2))
		return (test_integer_expression((ft_find_num(str)) ? str2 : str));
	num[0] = ft_strtol(str, NULL, 10);
	if (errno)
		return (test_integer_expression(str));
	num[1] = ft_strtol(str2, NULL, 10);
	if (errno)
		return (test_integer_expression(str2));
	if (num[0] != (int)num[0])
		return (test_integer_expression(str));
	if (num[1] != (int)num[1])
		return (test_integer_expression(str2));
	if (num[0] > num[1])
		return (0);
	return (1);
}

int		test_compare_int_less_or_equal(char *str, char *str2)
{
	long		num[2];

	errno = 0;
	num[0] = 0;
	num[1] = 0;
	if (ft_find_num(str) || ft_find_num(str2))
		return (test_integer_expression((ft_find_num(str)) ? str2 : str));
	num[0] = ft_strtol(str, NULL, 10);
	if (errno)
		return (test_integer_expression(str));
	num[1] = ft_strtol(str2, NULL, 10);
	if (errno)
		return (test_integer_expression(str2));
	if (num[0] != (int)num[0])
		return (test_integer_expression(str));
	if (num[1] != (int)num[1])
		return (test_integer_expression(str2));
	if (num[0] <= num[1])
		return (0);
	return (1);
}

int		test_compare_int_more_or_equal(char *str, char *str2)
{
	long		num[2];

	errno = 0;
	num[0] = 0;
	num[1] = 0;
	if (ft_find_num(str) || ft_find_num(str2))
		return (test_integer_expression((ft_find_num(str)) ? str2 : str));
	num[0] = ft_strtol(str, NULL, 10);
	if (errno)
		return (test_integer_expression(str));
	num[1] = ft_strtol(str2, NULL, 10);
	if (errno)
		return (test_integer_expression(str2));
	if (num[0] != (int)num[0])
		return (test_integer_expression(str));
	if (num[1] != (int)num[1])
		return (test_integer_expression(str2));
	if (num[0] >= num[1])
		return (0);
	return (1);
}
