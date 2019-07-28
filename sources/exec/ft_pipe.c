/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipe.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggwin-go <ggwin-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/11 12:43:40 by ggwin-go          #+#    #+#             */
/*   Updated: 2019/07/28 19:12:06 by ggwin-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

static void		ft_execve(char **av, int fd)
{
	extern char	**environ;

	wait(NULL);
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

// int				main(void)
// {
// 	// char	*s0[] = {"/bin/ls", "-lh", NULL};
// 	// char	*s1[] = {"/bin/cat", "-e", NULL};
// 	// char	*s2[] = {"/usr/bin/wc", "-l", NULL};
// 	char	*s0[] = {"/bin/cat", NULL, NULL};
// 	char	*s1[] = {"/usr/bin/head", "-c", "5", NULL};
// 	char	***av;

// 	av = (char ***)ft_xmalloc(sizeof(char **) * 4);
// 	av[0] = s0;
// 	av[1] = s1;
// 	// av[2] = s2;
// 	av[2] = NULL;
// 	av[3] = NULL;
// 	ft_pipe(av, 1);
// 	return (0);
// }

int				main(void)
{
	char	*s0[] = {"/usr/bin/base64", "/dev/urandom", NULL};
	// char	*s1[] = {"/usr/bin/head", "-c", "1000", NULL};
	// char	*s2[] = {"/usr/bin/grep", "42", NULL};
	// char	*s3[] = {"/usr/bin/wc", "-l", NULL};
	// char	*s4[] = {"/usr/bin/sed", "-e", "'s/1/Yes/g'", "-e", "'s/0/No/g'", NULL};

	char	***av;

	av = (char ***)malloc(sizeof(char **) * 6);
	av[0] = s0;
	// av[1] = s1;
	// av[2] = s2;
	// av[3] = s3;
	// av[4] = s4;
	av[1] = NULL;
	ft_pipe(av, 1);
	return (0);
}
