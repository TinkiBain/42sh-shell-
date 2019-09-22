/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   call_subshell.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggwin-go <ggwin-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 14:06:19 by ggwin-go          #+#    #+#             */
/*   Updated: 2019/09/22 19:53:26 by ggwin-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

void			call_subshell(char *str, t_pjobs *local)
{
	char		*av[3];
	pid_t		pid;
	int			pipefd[2];
	extern char	**environ;

	av[0] = PROJECT_NAME;
	av[1] = NULL;
	if (pipe(pipefd) == -1)
		exit(-1);
	write(pipefd[1], str, ft_strlen(str));
	if ((pid = fork()) == 0)
	{
		dup2(pipefd[0], 0);
		close(pipefd[0]);
		close(pipefd[1]);
		if (local->flag == 1)
			setpgrp();
		if (execve(g_shell_path, av, environ) == -1)
			exit(-1);
	}
	close(pipefd[1]);
	close(pipefd[0]);
	local = ljobs_startet(str, local->flag, local->num, pid);
	if (local->flag == 0)
		ft_waitpid(pid);
	else
		ft_printf("[%d] [%d]\n", local->num, pid);
	set_result();
}
