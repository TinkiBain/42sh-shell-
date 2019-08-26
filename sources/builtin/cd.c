/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwisoky <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/22 15:30:05 by dwisoky           #+#    #+#             */
/*   Updated: 2019/08/25 20:31:19 by dwisoky          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"
#include "sh.h"

const char		*check_flag(const char **av, int *flag)
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

int				change_dir_variable(const char *dir, char ***env)
{
	int			return_value;

	if (!dir)
	{
		if (!(dir = ft_getenv("HOME", *env, 4)))
			dir = get_value_from_all_vars("HOME");
		if (!dir)
		{
			ft_putstr_fd(PROJECT_NAME ": cd: HOME not set\n", 2);
			return (1);
		}
	}
	else
	{
		if (!(dir = ft_getenv("OLDPWD", *env, 6)))
			dir = get_value_from_all_vars("OLDPWD");
		if (!dir)
		{
			ft_putstr_fd(PROJECT_NAME ": cd: OLDPWD not set\n", 2);
			return (1);
		}
	}
	if (!(return_value = change_dir_with_flag(dir)))
		ft_putendl_fd(get_value_from_all_vars("PWD"), 2);
	return (return_value);
}

char			**cd_fill_path(const char *dir)
{
	char		**arr;
	char		**new_arr;
	int			i;

	arr = ft_strsplit(get_value_from_all_vars("CDPATH"), ':');
	i = 0;
	while (arr && arr[i])
	{
		if (arr[i][ft_strlen(arr[i]) - 1] != '/')
			arr[i] = ft_strrejoin(arr[i], "/", 1);
		arr[i] = ft_strrejoin(arr[i], dir, 1);
		++i;
	}
	new_arr = (char**)xmalloc(sizeof(char*) * (i + 2));
	i = 0;
	while (arr && arr[i])
	{
		new_arr[i] = arr[i];
		++i;
	}
	new_arr[i] = ft_strdup(dir);
	new_arr[i + 1] = NULL;
	free(arr);
	return (new_arr);
}

int				last_check_cd(char **av, int i)
{
	if (av[i + 1])
		ft_putendl_fd(av[i], 2);
	ft_free_double_ptr_arr((void ***)&av);
	return (0);
}

int				ft_cd(const char **av, char ***env)
{
	int			flag;
	const char	*dir;
	char		**arr;
	int			return_value;
	int			i;

	flag = 0;
	dir = check_flag(av, &flag);
	if (flag < 0)
		return (1);
	if (!dir || ft_strequ(dir, "-"))
		return (change_dir_variable(dir, env));
	arr = cd_fill_path(dir);
	i = -1;
	while (arr[++i])
	{
		if (flag)
			return_value = change_dir_with_flag(arr[i]);
		else
			return_value = change_dir_without_flag(arr[i]);
		if (!return_value)
			return (last_check_cd(arr, i));
	}
	ft_free_double_ptr_arr((void ***)&arr);
	return (cd_error(dir));
}
