/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   call_exec.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggwin-go <ggwin-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 22:41:23 by ggwin-go          #+#    #+#             */
/*   Updated: 2019/08/09 19:56:11 by ggwin-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

static int	print_error_command(const char *cmd)
{
	ft_putstr(PROJECT_NAME ": command not found: ");
	ft_putendl(cmd);
	exit(1);
}

static int	call_nonbuilin_exec(const char *path,  char *const *av, char **env)
{
	if (!access(path, X_OK))
	{
		execve(path, av, env);
	}
	else
	{
		ft_putstr(PROJECT_NAME ": permission denied: ");
		ft_putendl(path);
		exit(1);
	}
	return (0);
}

int			call_exec(const char **av, char ***env)
{
	char		*p;

	if (ft_strequ(*av, "exit"))
		return (ft_exit(av + 1));
	else if (ft_strequ(*av, "cd"))
		return (ft_cd(av + 1, env));
	else if (ft_strequ(*av, "echo"))
		return (ft_echo(av + 1));
	else if (ft_strequ(*av, "setenv"))
		return (ft_setenv(av + 1));
	else if (ft_strequ(*av, "unsetenv"))
		return (ft_unsetenv(av + 1));
	else if (ft_strequ(*av, "hash"))
		return (ft_hash());
	else if (ft_strequ(*av, "type"))
		return (ft_type(av + 1));
	else if ((p = get_bin((char *)*av)))
		return (call_nonbuilin_exec((const char *)p, (char *const *)av, *env));
	else if (ft_strchr(*av, '/'))
		return (call_nonbuilin_exec(*av, (char *const *)av, *env));
	else
		return (print_error_command(*av));
}
