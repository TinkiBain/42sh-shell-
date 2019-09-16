/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_test_compare_str.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wtalea <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 13:58:09 by wtalea            #+#    #+#             */
/*   Updated: 2019/09/16 14:39:16 by gmelisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_test.h"

int		test_compare_str_equal(char *str, char *dobstr)
{
	if (ft_strequ(str, dobstr))
		return (0);
	return (1);
}

int		test_compare_str_not_equal(char *str, char *dobstr)
{
	if (!ft_strequ(str, dobstr))
		return (0);
	return (1);
}
