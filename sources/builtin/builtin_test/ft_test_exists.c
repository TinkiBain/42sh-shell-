/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_test_exists.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wtalea <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/31 20:53:36 by wtalea            #+#    #+#             */
/*   Updated: 2019/09/14 19:26:33 by wtalea           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin_test.h"
#include <sys/stat.h>

int		test_file_exists(char *str)
{
	if (!access(str, F_OK))
		return (0);
	return (1);
}

int		test_file_set_group_id(char *str)
{
	struct stat	stats;

	if (!access(str, F_OK))
	{
		lstat(str, &stats);
		if (S_ISGID & (stats.st_mode))
			return (0);
	}
	return (1);
}

int		test_file_set_user_id(char *str)
{
	struct stat	stats;

	if (!access(str, F_OK))
	{
		lstat(str, &stats);
		if (S_ISUID & (stats.st_mode))
			return (0);
	}
	return (1);
}

int		test_file_pipe(char *str)
{
	struct stat	stats;

	if (!access(str, F_OK))
	{
		lstat(str, &stats);
		if (S_ISFIFO(stats.st_mode))
			return (0);
	}
	return (1);
}

int		test_file_read(char *str)
{
	if (!access(str, R_OK))
		return (0);
	return (1);
}
