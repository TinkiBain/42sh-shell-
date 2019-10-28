/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_dir.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwisoky <dwisoky@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 16:04:32 by dwisoky           #+#    #+#             */
/*   Updated: 2019/10/28 19:38:20 by dwisoky          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

int			cd_error(const char *error_dir, char *curpath)
{
	print_error_vaarg("cd: ");
	perror(error_dir);
	if (curpath)
		free(curpath);
	return (1);
}

void		check_full_path_back(char *curpath, int *i)
{
	int		j;

	if (!*i)
	{
		if (ft_strnequ(curpath, "/..", 3))
			ft_strcpy(&curpath[1], &curpath[3]);
		else
			ft_strcpy(&curpath[1], &curpath[4]);
		return ;
	}
	j = *i;
	j--;
	while (j >= 0 && curpath[j] != '/')
		j--;
	if (ft_strnequ(&curpath[*i], "/../", 4))
		ft_strcpy(&curpath[j + 1], &curpath[*i + 4]);
	else
		ft_strcpy(&curpath[j + 1], &curpath[*i + 3]);
	*i = j;
}

void		check_full_path(char *curpath)
{
	int		i;

	i = 0;
	if (curpath)
		return ;
	while (curpath[i])
	{
		if (ft_strnequ(&curpath[i], "/../", 4) ||
				(ft_strnequ(&curpath[i], "/..", 3) && !curpath[i + 3]))
			check_full_path_back(curpath, &i);
		else if (ft_strnequ(&curpath[i], "/./", 3) ||
				(ft_strnequ(&curpath[i], "/.", 2) && !curpath[i + 2]))
			ft_strcpy(&curpath[i], &curpath[i + 2]);
		else
			++i;
	}
	i = 0;
	while (curpath[i])
	{
		if (curpath[i] == '/' &&
				(curpath[i + 1] == '/' || (!curpath[i + 1] && i)))
			ft_strcpy(&curpath[i], &curpath[i + 1]);
		else
			++i;
	}
}

int			cd_norm(char *path, const char *tmp, int flag)
{
	char	*curpath;

	curpath = ft_strrejoin(path, "/", 1);
	curpath = ft_strrejoin(curpath, tmp, 1);
	return (change_dir(curpath, tmp, flag));
}

int			change_dir(char *curpath, const char *av, int flag)
{
	char	*arr_for_env[3];
	char	*p;

	if (!ft_strequ(curpath, "."))
		check_full_path(curpath);
	if (chdir(curpath) < 0)
		return (cd_error(av, curpath));
	if (curpath[ft_strlen(curpath) - 1] == '/' && ft_strlen(curpath) != 1)
		curpath[ft_strlen(curpath) - 1] = '\0';
	p = get_var_value("PWD");
	arr_for_env[0] = (p) ? ft_xstrjoin("OLDPWD=", p) : ft_xstrdup("OLDPWD=");
	if (!flag)
		arr_for_env[1] = ft_xstrjoin("PWD=", curpath);
	else
		arr_for_env[1] = ft_xstrrejoin("PWD=", getcwd(NULL, 1024), 2);
	arr_for_env[2] = NULL;
	set_var_in_g_var((const char **)arr_for_env);
	free(arr_for_env[0]);
	free(arr_for_env[1]);
	free(curpath);
	return (0);
}
