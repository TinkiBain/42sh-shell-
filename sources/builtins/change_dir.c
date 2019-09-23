/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_dir.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggwin-go <ggwin-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 16:04:32 by dwisoky           #+#    #+#             */
/*   Updated: 2019/09/22 21:23:38 by ggwin-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

int			cd_error(const char *error_dir, char *curpath)
{
	ft_putstr_fd(g_project_name, 2);
	ft_putstr_fd(": cd: ", 2);
	perror(error_dir);
	if (curpath)
		free(curpath);
	return (1);
}

int			change_dir(char *curpath, const char *av, int flag, char ***env)
{
	char	*arr_for_env[3];
	int		fd;
	char	dir_path[1024];

	if ((fd = open(curpath, O_DIRECTORY)) < 0)
		return (cd_error(av, curpath));
	if (fcntl(fd, F_GETPATH, dir_path) == -1)
		return (cd_error(av, curpath));
	free(curpath);
	curpath = ft_strdup(dir_path);
	if (chdir(curpath) < 0)
		return (cd_error(av, curpath));
	arr_for_env[0] = ft_strjoin("OLDPDW=", get_var_value("PWD"));
	printf("%s\n", curpath);
	if (!flag)
		arr_for_env[1] = ft_strjoin("PWD=", curpath);
	else
		arr_for_env[1] = ft_strrejoin("PWD=", getcwd(NULL, 1024), 2);
	arr_for_env[2] = NULL;
	set_var_in_g_var((const char **)arr_for_env);
	free(arr_for_env[0]);
	free(arr_for_env[1]);
	free(curpath);
	(void)env;
	return (0);
}
