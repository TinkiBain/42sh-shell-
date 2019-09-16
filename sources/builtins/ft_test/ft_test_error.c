/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_test_error.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wtalea <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/31 17:16:37 by wtalea            #+#    #+#             */
/*   Updated: 2019/09/16 14:37:11 by gmelisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_test.h"
#include "defs.h"

int		test_unary(char *src)
{
	write(2, PROJECT_NAME, ft_strlen(PROJECT_NAME));
	write(2, ": test: ", 8);
	write(2, src, ft_strlen(src));
	write(2, ": unary operator expected\n", 26);
	return (2);
}

int		test_too_many(void)
{
	write(2, "test: too many arguments\n", 25);
	return (2);
}

int		test_integer_expression(char *src)
{
	write(2, PROJECT_NAME, ft_strlen(PROJECT_NAME));
	write(2, ": test: ", 8);
	write(2, src, ft_strlen(src));
	write(2, ": integer expression expected\n", 30);
	return (2);
}
