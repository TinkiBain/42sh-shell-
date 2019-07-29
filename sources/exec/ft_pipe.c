/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipe.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggwin-go <ggwin-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/11 12:43:40 by ggwin-go          #+#    #+#             */
/*   Updated: 2019/06/11 12:44:59 by ggwin-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

static void		ft_execve(char **av, int fd)
{
	extern char	**environ;

	if (fork() == 0)
	{
		dup2(fd, 0);
		execve(*av, av, environ);
	}
}

void			ft_pipe(char ***av, int fd)
{
	extern char	**environ;
	pid_t		pid;
	int			pipefd[2];

	if (pipe(pipefd) < -1)
		exit(-1);
	if ((pid = fork()) == 0)
	{
		close(pipefd[0]);
		dup2(fd, 0);
		dup2(pipefd[1], 1);
		close(pipefd[1]);
		execve(**av, *av, environ);
	}
	else
	{
		wait(NULL);
		close(pipefd[1]);
		if (*(av + 2) != NULL)
			ft_pipe(++av, pipefd[0]);
		else
			ft_execve(*(++av), pipefd[0]);
		close(pipefd[0]);
	}
}
