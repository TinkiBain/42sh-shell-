/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_handle_pipe.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggwin-go <ggwin-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/11 12:43:40 by ggwin-go          #+#    #+#             */
/*   Updated: 2019/08/02 17:57:47 by ggwin-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"
#include "signal.h"

void			ast_handle_pipe(char ***av, int fd)
{
	extern char	**environ;
	pid_t		pid;
	pid_t		pid1;
	pid_t		pid2;
	int			pipefd[2];

	if (pipe(pipefd) == -1)
		exit(-1);
	if ((pid1 = fork()) == 0)
	{
		close(pipefd[0]);
		dup2(fd, 0);
		dup2(pipefd[1], 1);
		close(pipefd[1]);
		execve(**av, *av, environ);
	}
	else
	{
		++av;
		if ((pid2 = fork()) == 0)
		{
			close(pipefd[1]);
			dup2(pipefd[0], 0);
			close(pipefd[0]);
			execve(**av, *av, environ);
		}
		// close(pipefd[1]);
		// close(pipefd[0]);
	}
	close(pipefd[1]);
	close(pipefd[0]);
	waitpid(pid1, NULL, 0);
	waitpid(pid2, NULL, 0);
}

int				main(void)
{
	// char	*s0[] = {"/bin/ls", "-lh", NULL};
	// char	*s1[] = {"/bin/cat", "-e", NULL};
	// char	*s2[] = {"/usr/bin/wc", "-l", NULL};
	char	*s0[] = {"/bin/cat", "-e", NULL};
	char	*s1[] = {"/usr/bin/head", "-c" ,"5", NULL};
	char	***av;

	av = (char ***)ft_xmalloc(sizeof(char **) * 4);
	av[0] = s0;
	av[1] = s1;
	// av[2] = s2;
	av[2] = NULL;
	av[3] = NULL;
	ast_handle_pipe(av, 0);
	return (0);
}
