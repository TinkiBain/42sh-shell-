/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_builtin.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggwin-go <ggwin-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/03 19:32:27 by ggwin-go          #+#    #+#             */
/*   Updated: 2019/08/16 22:04:20 by ggwin-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

static int	print_error(const char *cmd, const char *error)
{
	ft_putstr_fd(PROJECT_NAME ": ", 2);
	ft_putstr_fd(cmd, 2);
	ft_putendl_fd(error, 2);
	return (-1);
}

static int	cmd_is_exist(const char *cmd)
{
	if (!get_bin((char *)cmd))
		return (print_error(cmd, ": command not found"));
	return (0);
}

static int	check_cmd(const char *cmd)
{
	const char		*p;
	struct stat		st;

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
	{
		if (stat(cmd, &st) == -1)
			return (print_error(cmd, ": No such file or directory"));
		if (S_ISDIR(st.st_mode))
			return (print_error(cmd, ": Is a directory"));
		else if (!S_ISREG(st.st_mode))
			return (print_error(cmd, ": No such file or directory"));
		else if (access(cmd, X_OK))
			return (print_error(cmd, ": Permission denied"));
	}
	else
		return (cmd_is_exist(cmd));
	return (0);
}

int			check_builtin(const char *cmd)
{
	if (ft_strequ(cmd, "exit") || ft_strequ(cmd, "cd") ||
			ft_strequ(cmd, "echo") || ft_strequ(cmd, "type") ||
			ft_strequ(cmd, "setenv") || ft_strequ(cmd, "unsetenv") ||
			ft_strequ(cmd, "hash") || ft_strequ(cmd, "env") ||
			ft_strequ(cmd, "set") || ft_strequ(cmd, "unset"))
		return (1);
	return (check_cmd(cmd));
}
