/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   call_exec.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggwin-go <ggwin-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 22:41:23 by ggwin-go          #+#    #+#             */
/*   Updated: 2019/08/03 21:46:01 by ggwin-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

static int		print_error_command(char *s)
{
	ft_putstr(PROJECT_NAME);
	ft_putstr(": command not found: ");
	ft_putendl(s);
	return (1);
}

static int		call_nonbuilin_exec(char *path, char **split, char **env)
{
	pid_t		pid;

	if (!access(path, X_OK))
	{
		pid = fork();
		if (!pid)
			execve(path, split, env);
		waitpid(pid, NULL, 0);
	}
	else
	{
		ft_putstr(PROJECT_NAME);
		ft_putstr(": permission denied: ");
		ft_putendl(path);
	}
	return (1);
}

void			call_exec(char **split, char ***env)
{
	char		*tmp;
	char		*p;

	if (ft_strequ(split[0], "exit"))
		exit(EXIT_SUCCESS);
	else if (ft_strequ(split[0], "cd"))
		ft_cd(split + 1);
	else if (ft_strequ(split[0], "echo"))
		ft_echo(split + 1);
	else if (ft_strequ(split[0], "env"))
		ft_env(split + 1, *env);
	else if (ft_strequ(split[0], "setenv"))
		ft_setenv(split + 1);
	else if (ft_strequ(split[0], "unsetenv"))
		ft_unsetenv(split + 1);
	else if (ft_strequ(split[0], "hash"))
		ft_hash();
	else if ((p = get_bin(split[0], g_table)))
	{
		tmp = split[0];
		split[0] = p;
		call_nonbuilin_exec(tmp, split, *env);
	}
	else if (ft_strchr(split[0], '/'))
		call_nonbuilin_exec(split[0], split, *env);
	else
		print_error_command(split[0]);
}
