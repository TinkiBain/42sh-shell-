/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tilda.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggwin-go <ggwin-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/27 18:08:41 by jterry            #+#    #+#             */
/*   Updated: 2019/08/18 00:18:12 by ggwin-go         ###   ########.fr       */
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

	tmp = ft_xstrdup(&str[1]);
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
		return (ft_xstrdup(get_value_from_all_vars("PWD")));
	else if (str[1] == '-' && !str[2])
	{
		if ((buf = get_value_from_all_vars("OLDPWD")) < 0)
			return (ft_xstrdup(buf));
	}
	else if (str[1] == '/')
	{
		buf = get_value_from_all_vars("HOME");
		buf = ft_strrejoin(buf, &str[1], 0);
		return (buf);
	}
	else if (str[1])
		return (user_founder(str));
	else
		buf = get_value_from_all_vars("HOME");
	return (ft_xstrdup(buf));
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
