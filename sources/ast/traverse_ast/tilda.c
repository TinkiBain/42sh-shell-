/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tilda.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jterry <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/27 18:08:41 by jterry            #+#    #+#             */
/*   Updated: 2019/08/12 19:21:12 by jterry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

extern char **environ;

static int			dirdir(char *str)
{
	struct dirent	*entry;
	DIR				*dirent;

	dirent = opendir("/Users");
	while ((entry = readdir(dirent)))
	{
		if (ft_strcmp(str, entry->d_name) == 0)
		{
			closedir(dirent);
			return (1);
		}
	}
	closedir(dirent);
	return (-1);
}

static char			*user_founder(char *str)
{
	char			*tmp;

	tmp = ft_strdup(&str[1]);
	if (dirdir(tmp) < 0)
	{
		free(tmp);
		return (NULL);
	}
	tmp = ft_strrejoin("/Users/", tmp, 2);
	return (tmp);
}

static char			*tilda(char *str, char *buf)
{
	if (str[1] == '+' && !str[2])
		return (ft_strdup(ft_getenv("PWD", environ)));
	else if (str[1] == '-' && !str[2])
	{
		if ((buf = ft_getenv("OLDPWD", environ)) < 0)
			return (ft_strdup(buf));
	}
	else if (str[1] == '/')
	{
		buf = ft_getenv("HOME", environ);
		buf = ft_strrejoin(buf, &str[1], 0);
		return (buf);
	}
	else if (str[1])
		return (user_founder(str));
	else
		buf = ft_getenv("HOME", environ);
	return (ft_strdup(buf));
}

char				*tilda_check(char *str)
{
	char			*tmp;

	if (*str == '~')
	{
		if (!(tmp = tilda(str, NULL)))
		{
			free(tmp);
			return (NULL);
		}
		free(str);
		return (tmp);
	}
	return (NULL);
}
