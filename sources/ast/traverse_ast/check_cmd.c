/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggwin-go <ggwin-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/25 18:47:59 by ggwin-go          #+#    #+#             */
/*   Updated: 2019/08/26 12:41:08 by ggwin-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

static int	return_error(const char *cmd, const char *error)
{
	print_error(cmd, error);
	return (-1);
}

static int	cmd_is_exist(const char *cmd)
{
	if (!get_bin((char *)cmd))
		return (return_error(cmd, ": command not found"));
	return (0);
}

static int	check_cmd_errors(const char *cmd)
{
	struct stat		st;

	if (stat(cmd, &st) == -1)
		return (return_error(cmd, ": No such file or directory"));
	if (S_ISDIR(st.st_mode))
		return (return_error(cmd, ": Is a directory"));
	else if (!S_ISREG(st.st_mode))
		return (return_error(cmd, ": No such file or directory"));
	else if (access(cmd, X_OK))
		return (return_error(cmd, ": Permission denied"));
	return (0);
}

int			check_cmd(const char *cmd)
{
	const char		*p;

	p = cmd;
	while (*p)
	{
		if (*p == '/')
			break ;
		else if (*p == '\\' && *(p + 1))
			++p;
		++p;
	}
	if (*p == '/')
		return (check_cmd_errors(cmd));
	else
		return (cmd_is_exist(cmd));
}
