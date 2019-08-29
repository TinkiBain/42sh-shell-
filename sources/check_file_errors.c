/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file_errors.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggwin-go <ggwin-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/29 19:26:54 by ggwin-go          #+#    #+#             */
/*   Updated: 2019/08/29 20:52:26 by ggwin-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

int	return_error(const char *file_name, const char *error)
{
	extern char	**g_var;

	print_error(file_name, error);
	g_res_exec = 127;
	set_var("?=127", &g_var, 1);
	return (127);
}

int	check_file_errors(const char *file_name, int flag)
{
	struct stat		st;

	if (stat(file_name, &st) == -1)
		return (return_error(file_name, ": No such file or directory"));
	if (S_ISDIR(st.st_mode))
		return (return_error(file_name, ": Is a directory"));
	else if (!S_ISREG(st.st_mode))
		return (return_error(file_name, ": No such file or directory"));
	else if (access(file_name, flag))
		return (return_error(file_name, ": Permission denied"));
	return (0);
}
