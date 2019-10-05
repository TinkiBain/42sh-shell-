/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwisoky <dwisoky@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 21:05:54 by dwisoky           #+#    #+#             */
/*   Updated: 2019/10/05 20:00:23 by dwisoky          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

const char	*check_flag(const char **av, int *flag)
{
	while (*av)
	{
		if (**av == '-' && *(*av + 1))
		{
			++(*av);
			while (**av)
			{
				if (**av == 'L')
					*flag = 0;
				else if (**av == 'P')
					*flag = 1;
				else
				{
					*flag = -1;
					return (cd_error_invalid_flag(**av));
				}
				++(*av);
			}
		}
		else
			return (*av);
		++av;
	}
	return (NULL);
}

void		*cd_error_invalid_flag(char c)
{
	ft_putstr_fd(g_project_name, 2);
	ft_putstr_fd(": cd: -", 2);
	write(2, &c, 1);
	ft_putstr_fd(": invalid option\ncd: usage: cd [-L|-P] [dir]\n", 2);
	return (NULL);
}

int			change_dir_variable(const char *dir)
{
	if (!dir)
	{
		dir = get_var_value("HOME");
		if (!dir)
		{
			ft_putstr_fd(g_project_name, 2);
			ft_putstr_fd(": cd: HOME not set\n", 2);
			return (1);
		}
	}
	else
	{
		dir = get_var_value("OLDPWD");
		if (!dir)
		{
			ft_putstr_fd(g_project_name, 2);
			ft_putstr_fd(": cd: OLDPWD not set\n", 2);
			return (1);
		}
		ft_putendl(dir);
	}
	dir = ft_strdup(dir);
	return (change_dir((char *)dir, (char *)dir, 1));
}

char		*check_cdpath(const char *curpath)
{
	struct stat	st;
	char		**arr_cd_path;
	char		*cdpath;
	int			i;

	i = 0;
	cdpath = get_var_value("CDPATH");
	if (!cdpath)
		return (NULL);
	arr_cd_path = ft_strsplit(cdpath, ':');
	while (arr_cd_path[i])
	{
		arr_cd_path[i] = ft_strrejoin(arr_cd_path[i], "/", 1);
		cdpath = ft_strjoin(arr_cd_path[i], curpath);
		if (stat(cdpath, &st))
			free(cdpath);
		else if (st.st_mode & S_IFDIR)
			break ;
		else
			free(cdpath);
		cdpath = NULL;
	}
	ft_free_double_ptr_arr((void ***)&arr_cd_path);
	return (cdpath);
}

int			ft_cd(const char **av)
{
	char		*curpath;
	char		*path;
	const char	*tmp;
	int			flag;

	flag = 0;
	tmp = check_flag(av, &flag);
	if (flag < 0)
		return (1);
	if (!tmp || ft_strequ(tmp, "-"))
		return (change_dir_variable(tmp));
	if (*tmp == '/')
		return (change_dir(ft_strdup(tmp), tmp, flag));
	path = ft_strdup(get_var_value("PWD"));
	if (!path)
		path = ft_strdup(getcwd(NULL, 1024));
	if (ft_strnequ(tmp, "./", 2) || ft_strnequ(tmp, "../", 3))
	{
		curpath = ft_strrejoin(path, "/", 1);
		curpath = ft_strrejoin(curpath, tmp, 1);
		return (change_dir(curpath, tmp, flag));
	}
	if ((curpath = check_cdpath(tmp)))
		return (change_dir(curpath, tmp, flag));
	curpath = ft_strrejoin(path, "/", 1);
	return (change_dir(ft_strrejoin(curpath, tmp, 1), tmp, flag));
}
