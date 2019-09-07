/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_test_compare.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wtalea <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 13:37:33 by wtalea            #+#    #+#             */
/*   Updated: 2019/09/07 17:09:37 by wtalea           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin_test.h"

int			test_check_compare(char **argv)
{
	if (ft_strequ("=", *(argv + 1)))
		return (test_compare_str_equal(*argv, *(argv + 2)));
	if (ft_strequ("!=", *(argv + 1)))
		return (test_compare_str_not_equal(*argv, *(argv + 2)));
	if (ft_strequ("-eq", *(argv + 1)))
		return (test_compare_int_equal(*argv, *(argv + 2)));
	if (ft_strequ("-ne", *(argv + 1)))
		return (test_compare_int_not_equal(*argv, *(argv + 2)));
	if (ft_strequ("-lt", *(argv + 1)))
		return (test_compare_int_less(*argv, *(argv + 2)));
	if (ft_strequ("-le", *(argv + 1)))
		return (test_compare_int_less_or_equal(*argv, *(argv + 2)));
	if (ft_strequ("-gt", *(argv + 1)))
		return (test_compare_int_more(*argv, *(argv + 2)));
	if (ft_strequ("-ge", *(argv + 1)))
		return (test_compare_int_more_or_equal(*argv, *(argv + 2)));
	test_unary(*(argv + 1));
	return (2);
}
