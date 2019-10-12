/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_test_type.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wtalea <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/31 19:52:40 by wtalea            #+#    #+#             */
/*   Updated: 2019/10/12 14:29:22 by wtalea           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_test.h"
#include <sys/stat.h>

int		test_file_symbol(char *str)
{
	struct stat	stats;

	if (!access(str, F_OK))
	{
		stat(str, &stats);
		if (S_ISCHR(stats.st_mode))
			return (0);
	}
	return (1);
}

int		test_file_dir(char *str)
{
	struct stat	stats;

	if (!access(str, F_OK))
	{
		stat(str, &stats);
		if (S_ISDIR(stats.st_mode))
			return (0);
	}
	return (1);
}

int		test_file_link(char *str)
{
	struct stat	stats;

	if (!access(str, F_OK))
	{
		lstat(str, &stats);
		if (S_ISLNK(stats.st_mode))
			return (0);
	}
	return (1);
}

int		test_file_socket(char *str)
{
	struct stat	stats;

	if (!access(str, F_OK))
	{
		stat(str, &stats);
		if (S_ISSOCK(stats.st_mode))
			return (0);
	}
	return (1);
}

int		test_file_usual(char *str)
{
	struct stat	stats;

	if (!access(str, F_OK))
	{
		stat(str, &stats);
		if (S_ISREG(stats.st_mode))
			return (0);
	}
	return (1);
}
