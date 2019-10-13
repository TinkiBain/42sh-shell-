/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwisoky <dwisoky@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 21:05:54 by dwisoky           #+#    #+#             */
/*   Updated: 2019/10/13 18:09:52 by dwisoky          ###   ########.fr       */
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
	print_error_vaarg("cd: -%c: invalid option\n", c);
	ft_putstr_fd("cd: usage: cd [-L|-P] [dir]\n", STDERR);
	return (NULL);
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
		arr_cd_path[i] = ft_xstrrejoin(arr_cd_path[i], "/", 1);
		cdpath = ft_xstrjoin(arr_cd_path[i], curpath);
		if (stat(cdpath, &st))
			free(cdpath);
		else if (st.st_mode & S_IFDIR)
			break ;
		else
			free(cdpath);
		cdpath = NULL;
	}
	ft_free_ptr_array((void ***)&arr_cd_path);
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
		return (change_dir_variable(tmp, flag));
	if (*tmp == '/')
		return (change_dir(ft_xstrdup(tmp), tmp, flag));
	if (!flag)
		path = ft_xstrdup(get_var_value("PWD"));
	else
		path = getcwd(NULL, 1024);
	if (!path)
		path = ft_xstrdup(getcwd(NULL, 1024));
	if (ft_strnequ(tmp, "./", 2) || ft_strnequ(tmp, "../", 3))
		return (cd_norm(path, tmp, flag));
	if ((curpath = check_cdpath(tmp)))
		return (change_dir(curpath, tmp, flag));
	curpath = ft_xstrrejoin(path, "/", 1);
	return (change_dir(ft_xstrrejoin(curpath, tmp, 1), tmp, flag));
}
