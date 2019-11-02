/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwisoky <dwisoky@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 21:05:54 by dwisoky           #+#    #+#             */
/*   Updated: 2019/11/02 18:01:05 by dwisoky          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

char		*check_path(char *path)
{
	struct stat		stat_path;
	struct stat		stat_cwd;
	char			*cwd;

	if (!path)
		return (getcwd(NULL, 1024));
	cwd = getcwd(NULL, 1024);
	if (stat(path, &stat_path) == -1)
	{
		free(path);
		return (cwd);
	}
	stat(cwd, &stat_cwd);
	if (stat_path.st_ino == stat_cwd.st_ino &&
			stat_path.st_dev == stat_cwd.st_dev)
	{
		free(cwd);
		return (path);
	}
	free(path);
	return (cwd);
}

int			change_dir_variable(const char *dir, int flag)
{
	if (!dir)
	{
		dir = get_var_value("HOME");
		if (!dir)
		{
			print_error("cd", "HOME not set");
			return (1);
		}
	}
	else
	{
		dir = get_var_value("OLDPWD");
		if (!dir)
		{
			print_error("cd", "OLDPWD not set");
			return (1);
		}
		ft_putendl(dir);
	}
	dir = ft_xstrdup(dir);
	return (change_dir((char *)dir, (char *)dir, flag));
}

char		*check_cdpath(const char *curpath, char *path)
{
	struct stat	st;
	char		**arr_cd_path;
	char		*cdpath;
	int			i;

	i = -1;
	if (!(cdpath = get_var_value("CDPATH")))
		return (NULL);
	arr_cd_path = ft_strsplit(cdpath, ':');
	while (arr_cd_path[++i])
	{
		arr_cd_path[i] = ft_xstrrejoin(arr_cd_path[i], "/", 1);
		cdpath = ft_xstrjoin(arr_cd_path[i], curpath);
		if (stat(cdpath, &st) == -1)
			free(cdpath);
		else if (st.st_mode & S_IFDIR)
			break ;
		else
			free(cdpath);
		cdpath = NULL;
	}
	ft_free_ptr_array((void ***)&arr_cd_path);
	if (cdpath)
		free(path);
	return (cdpath);
}

int			ft_cd(const char **av)
{
	char		*curpath;
	char		*path;
	const char	*tmp;
	int			flag;

	flag = 0;
	tmp = cd_check_flag(av, &flag);
	if (flag < 0)
		return (1);
	if (!tmp || ft_strequ(tmp, "-"))
		return (change_dir_variable(tmp, flag));
	if (*tmp == '/')
		return (change_dir(ft_xstrdup(tmp), tmp, flag));
	if (!flag)
		path = ft_xstrdup(get_var_value("PWD"));
	else
		path = getcwd(NULL, 1024);
	path = check_path(path);
	if (ft_strnequ(tmp, "./", 2) || ft_strnequ(tmp, "../", 3))
		return (cd_norm(path, tmp, flag));
	if ((curpath = check_cdpath(tmp, path)))
		return (change_dir(curpath, tmp, flag));
	curpath = ft_xstrrejoin(path, "/", 1);
	return (change_dir(ft_xstrrejoin(curpath, tmp, 1), tmp, flag));
}
