/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggwin-go <ggwin-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 00:30:09 by ggwin-go          #+#    #+#             */
/*   Updated: 2019/08/04 22:41:15 by ggwin-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"
#include <stdio.h>

static char	*get_previous_pwd(char **env)
{
	char	*p;

	if (!env || !*env)
		return (getcwd(NULL, 1024));
	while (*env && !ft_strnequ(*env, "OLDPWD=", 7))
		++env;
	if (*env)
	{
		p = ft_strchr(*env, '=');
		ft_putendl(p + 1);
		return (ft_strdup(p + 1));
	}
	return (getcwd(NULL, 1024));
}

static void	change_dir(char *path)
{
	char	**arr;

	arr = (char **)malloc(sizeof(char *) * 3);
	arr[0] = ft_strjoin_free("OLDPWD=", getcwd(NULL, 1024), 2);
	chdir(path);
	arr[1] = ft_strjoin_free("PWD=", getcwd(NULL, 1024), 2);
	arr[2] = NULL;
	ft_setenv(arr);
	free(arr);
}

static void	cd_error(char *av, int tilda_error)
{
	if (!(*av == '~' && tilda_error))
	{
		ft_putstr(PROJECT_NAME ": cd: ");
		perror(av);
	}
}

static void	ft_open_dir(char *av, char ***env)
{
	DIR		*dp;
	char	*path;
	int		has_replaceable_tilda;

	has_replaceable_tilda = 1;
	if (!av)
		path = ft_strdup(getenv("HOME"));
	else if (av[0] == '-')
		path = get_previous_pwd(*env);
	else
		path = ft_strdup(av);
	if (path && (dp = opendir(path)) != NULL)
	{
		change_dir(path);
		closedir(dp);
	}
	else
		cd_error(av, has_replaceable_tilda);
	free(path);
}

int			ft_cd(char **av)
{
	extern char	**environ;

	if (!av)
		return (0);
	if (!av[0])
		ft_open_dir(NULL, &environ);
	else if (av[1] != NULL)
	{
		ft_putstr(PROJECT_NAME ": cd: too many arguments");
	}
	else
		ft_open_dir(av[0], &environ);
	return (1);
}
