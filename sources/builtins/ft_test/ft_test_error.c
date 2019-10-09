/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_test_error.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wtalea <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/31 17:16:37 by wtalea            #+#    #+#             */
/*   Updated: 2019/10/09 18:04:49 by gmelisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_test.h"
#include "defs.h"
#include "error.h"

int		test_unary(char *src)
{
	print_error_vaarg("test: %s: unary operator expected\n", src);
	return (2);
}

int		test_too_many(void)
{
	print_error("test", "too many arguments");
	return (2);
}

int		test_integer_expression(char *src)
{
	print_error_vaarg("test: %s: integer expression expected\n", src);
	return (2);
}
