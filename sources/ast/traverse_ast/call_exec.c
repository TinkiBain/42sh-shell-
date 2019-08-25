/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   call_exec.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggwin-go <ggwin-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 22:41:23 by ggwin-go          #+#    #+#             */
/*   Updated: 2019/08/25 22:01:50 by gmelisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

/*
**	When execve() return -1 in function call_nonbuilin_exec()
**	need to call our shel for execute script.
*/

static int	call_nonbuilin_exec(const char *path, char *const *av, char **env)
{
	if (!access(path, X_OK))
	{
		if (execve(path, av, env) == -1)
		{
			ft_putstr_fd(PROJECT_NAME ": ", 1);
			ft_putstr_fd(av[0], 2);
			ft_putendl_fd(": execve return (-1) from call_exec()", 2);
			exit(-1);
		}
	}
	else
	{
		ft_putstr_fd(PROJECT_NAME ": permission denied: ", 2);
		ft_putendl_fd(path, 2);
		exit(1);
	}
	return (0);
}

static int	call_if_builtin(const char **av, char ***env)
{
	if (ft_strequ(*av, "exit"))
		return (ft_exit(av + 1));
	else if (ft_strequ(*av, "cd"))
		return (ft_cd(av + 1, env));
	else if (ft_strequ(*av, "echo"))
		return (ft_echo(av + 1));
	else if (ft_strequ(*av, "env"))
		return (ft_env(av + 1, *env));
	else if (ft_strequ(*av, "setenv"))
		return (ft_setenv(av + 1));
	else if (ft_strequ(*av, "unsetenv"))
		return (ft_unsetenv(av + 1));
	else if (ft_strequ(*av, "set"))
		return (ft_set(av + 1));
	else if (ft_strequ(*av, "unset"))
		return (ft_unset(av + 1));
	else if (ft_strequ(*av, "hash"))
		return (ft_hash((char **)av));
	else if (ft_strequ(*av, "type"))
		return (ft_type(av + 1));
	return (0);
}

int			call_exec(const char **av, char ***env)
{
	char	*p;
	int		res;

	if ((res = is_builtin(*av)) == 1)
		return (call_if_builtin(av, env));
	else
		res = check_cmd(*av);
	if (res == 0)
	{
		if ((p = get_bin((char *)*av)))
			return (call_nonbuilin_exec((const char *)p, (char *const *)av, *env));
		else if (ft_strchr(*av, '/'))
			return (call_nonbuilin_exec(*av, (char *const *)av, *env));
	}
	return (-1);
}
