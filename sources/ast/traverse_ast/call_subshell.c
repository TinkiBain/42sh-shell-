/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   call_subshell.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggwin-go <ggwin-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 14:06:19 by ggwin-go          #+#    #+#             */
/*   Updated: 2019/09/16 20:21:07 by ggwin-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

void	call_subshell(char *str, int sep, char **env, t_pjobs *local)
{
	char	*av[3];
	pid_t	pid;
	int		pipefd[2];

	av[0] = PROJECT_NAME;
	av[1] = NULL;
	local = jobs_startet(ft_xstrdup("pjobs_name_for_subshell"), sep);
	redir_set();
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
		if (execve(g_shell_path, av, env) == -1)
			exit(-1);
	}
	close(pipefd[1]);
	close(pipefd[0]);
	ljobs_startet(ft_xstrdup("subjobs_name_for_subshell"), local->flag, local->num, pid);
	if (local->flag == 0)
		ft_waitpid(pid);
	else
		ft_printf("[%d] [%d]\n", local->num, pid);
	redir_reset();
	set_result();
}
