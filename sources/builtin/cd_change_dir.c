/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_change_dir.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggwin-go <ggwin-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/22 16:27:06 by dwisoky           #+#    #+#             */
/*   Updated: 2019/08/29 17:28:09 by ggwin-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"
#include "sh.h"

int			cd_error(const char *dir)
{
	ft_putstr_fd(g_project_name, 2);
	ft_putstr_fd(": cd: ", 2);
	perror(dir);
	return (1);
}

void		*cd_error_invalid_flag(char c)
{
	ft_putstr_fd(g_project_name, 2);
	ft_putstr_fd(": cd: -", 2);
	write(2, &c, 1);
	ft_putstr_fd(": invalid option\ncd: usage: cd [-L|-P] [dir]\n", 2);
	return (NULL);
}

int			change_dir_with_flag(const char *dir)
{
	char	**arr;

	arr = (char**)xmalloc(sizeof(char *) * 3);
	arr[0] = ft_strrejoin("OLDPWD=", getcwd(NULL, 1024), 2);
	if (chdir(dir) < 0)
	{
		free(arr[0]);
		free(arr);
		return (1);
	}
	arr[1] = ft_strrejoin("PWD=", getcwd(NULL, 1024), 2);
	arr[2] = NULL;
	set_var_in_g_var((const char **)arr);
	ft_free_double_ptr_arr((void ***)&arr);
	return (0);
}

char		*cd_get_old_path_with_flag(void)
{
	char	*str;

	str = ft_strjoin("OLDPWD=", get_value_from_all_vars("PWD="));
	if (!str)
		str = ft_strdup("OLDPWD=");
	return (str);
}

int			change_dir_without_flag(const char *dir)
{
	int			fd;
	char		**arr;
	char		buf[1024];
	struct stat	st;

	if (lstat(dir, &st) < 0)
		return (1);
	if (st.st_mode & S_IFCHR)
	{
		fd = open(dir, O_SYMLINK);
		fcntl(fd, F_GETPATH, buf);
		if (change_dir_with_flag(dir))
			return (1);
		arr = (char**)xmalloc(sizeof(char *) * 3);
		arr[0] = ft_strjoin("PWD=", buf);
		arr[1] = cd_get_old_path_with_flag();
		arr[2] = NULL;
		set_var_in_g_var((const char **)arr);
		ft_free_double_ptr_arr((void ***)&arr);
		close(fd);
		return (0);
	}
	else
		return (change_dir_with_flag(dir));
}
