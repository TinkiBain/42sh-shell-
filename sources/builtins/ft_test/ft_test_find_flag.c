/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_test_find_flag.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wtalea <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/31 18:47:32 by wtalea            #+#    #+#             */
/*   Updated: 2019/10/12 15:20:18 by wtalea           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_test.h"

static	int	test_minus_continue(char c, char *src)
{
	if (c == 'u')
		return (test_file_set_user_id(src));
	else if (c == 'w')
		return (test_file_exists_and_write(src));
	else if (c == 'x')
		return (test_file_exists_and_exec(src));
	else if (c == 'z')
		return (test_string_null(src));
	else if (c == 'b')
		return (test_file_block(src));
	return (1);
}

static	int	test_minus(char c, char *src)
{
	if (c == 'c')
		return (test_file_symbol(src));
	else if (c == 'd')
		return (test_file_dir(src));
	else if (c == 'e')
		return (test_file_exists(src));
	else if (c == 'f')
		return (test_file_usual(src));
	else if (c == 'g')
		return (test_file_set_group_id(src));
	else if (c == 'L')
		return (test_file_link(src));
	else if (c == 'p')
		return (test_file_pipe(src));
	else if (c == 'r')
		return (test_file_read(src));
	else if (c == 's')
		return (test_file_exists_and_fat(src));
	else if (c == 'S')
		return (test_file_socket(src));
	return (test_minus_continue(c, src));
}

int			test_find_flag(char **argv)
{
	return (test_minus(*((*argv) + 1), *(argv + 1)));
}
