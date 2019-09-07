/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_test_exists_and_null.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wtalea <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/31 21:04:32 by wtalea            #+#    #+#             */
/*   Updated: 2019/09/07 17:11:53 by wtalea           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin_test.h"

int		test_file_exists_and_write(char *str)
{
	if (!access(str, W_OK))
		return (0);
	return (1);
}

int		test_file_exists_and_exec(char *str)
{
	if (!access(str, X_OK))
		return (0);
	return (1);
}

int		test_string_null(char *str)
{
	if (str && !*str)
		return (0);
	return (1);
}

int		test_file_exists_and_fat(char *str)
{
	struct stat	stats;

	if (!access(str, F_OK))
	{
		stat(str, &stats);
		if (stats.st_size > 0)
			return (0);
	}
	return (1);
}
