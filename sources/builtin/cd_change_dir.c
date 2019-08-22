/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_change_dir.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwisoky <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/22 16:27:06 by dwisoky           #+#    #+#             */
/*   Updated: 2019/08/22 17:40:45 by dwisoky          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"
#include "sh.h"

int		change_dir_with_flag(const char *dir)
{
	char	**arr;

	arr = (char**)xmalloc(sizeof(char *) * 3);
	arr[0] = ft_strrejoin("OLDPWD=", getcwd(NULL, 1024), 2);
	if (chdir(dir) < 0)
	{
		//proverka na PATHCD
		ft_putstr_fd(PROJECT_NAME ": cd: ", 2);
		ft_putstr_fd(dir, 2);
		ft_putstr_fd(": No such file or directory\n", 2);
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
