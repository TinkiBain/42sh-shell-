/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwisoky <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/22 15:30:05 by dwisoky           #+#    #+#             */
/*   Updated: 2019/08/22 17:26:57 by dwisoky          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"
#include "sh.h"

void		*cd_error_invalid_flag(char c)
{
	ft_putstr_fd(PROJECT_NAME ": cd: -", 2);
	write(2, &c, 1);
	ft_putstr_fd(": invalid option\ncd: usage: cd [-L|-P] [dir]\n", 2);
	return (NULL);
}

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
	return_value = change_dir_with_flag(dir);
	if (!return_value)
	{
		printf("Dsad\n");
		ft_putstr(get_value_from_all_vars("PWD"));
	}
	return (return_value);
}

int				ft_cd(const char **av, char ***env)
{
	int			flag;
	const char	*dir;
	
	flag = 0;
	dir = check_flag(av, &flag);
	if (flag < 0)
		return (1);
	if (!dir || ft_strequ(dir, "-"))
		return (change_dir_variable(dir, env));
//	else if (flag)
		return (change_dir_with_flag(dir));
//	else
//		return (change_dir_without_flag(dir));
}
