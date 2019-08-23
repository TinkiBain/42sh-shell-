/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggwin-go <ggwin-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 00:30:09 by ggwin-go          #+#    #+#             */
/*   Updated: 2019/08/21 17:40:46 by ggwin-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"
#include <stdio.h>

static char	*get_previous_pwd(char **env)
{
	char	*p;

	if (!env || !*env)
		return (getcwd(NULL, 1024));
	if ((p = get_value_from_all_vars("OLDPWD")))
		return (ft_xstrdup(p));
	return (getcwd(NULL, 1024));
}

static void	change_dir(char *path)
{
	char	**arr;

	arr = (char **)xmalloc(sizeof(char *) * 3);
	arr[0] = ft_strrejoin("OLDPWD=", getcwd(NULL, 1024), 2);
	chdir(path);
	arr[1] = ft_strrejoin("PWD=", getcwd(NULL, 1024), 2);
	arr[2] = NULL;
	ft_setenv((const char **)arr);
	ft_free_double_ptr_arr((void ***)&arr);
}

static void	cd_error(const char *av, int tilda_error)
{
	if (!(*av == '~' && tilda_error))
	{
		ft_putstr(PROJECT_NAME ": cd: ");
		perror(av);
	}
}

static void	ft_open_dir(const char *av, char ***env)
{
	DIR		*dp;
	char	*path;
	int		has_replaceable_tilda;

	has_replaceable_tilda = 1;
	if (!av)
		return ;
	else if (ft_strequ(av, "-"))
		path = get_previous_pwd(*env);
	else
		path = ft_xstrdup(av);
	if (path && (dp = opendir(path)) != NULL)
	{
		change_dir(path);
		closedir(dp);
	}
	else
		cd_error(av, has_replaceable_tilda);
	free(path);
}

int			ft_cd(const char **av, char ***env)
{
	struct passwd	*pw;

	if (!av)
		return (1);
	if (!av[0])
	{
		if ((pw = getpwuid(getuid())))
			ft_open_dir(pw->pw_dir, env);
	}
	else if (av[1] != NULL)
		ft_putstr(PROJECT_NAME ": cd: too many arguments");
	else
		ft_open_dir(av[0], env);
	return (0);
}
