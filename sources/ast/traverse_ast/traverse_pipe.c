/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   traverse_pipe.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggwin-go <ggwin-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 17:26:20 by ggwin-go          #+#    #+#             */
/*   Updated: 2019/09/09 21:04:05 by ggwin-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

static void		handle_last_cmd_in_pipe(int fd, t_simple_cmd *cmd, char **env,
												int in_fork, t_pjobs *local)
{
	pid_t		pid;

	if ((pid = fork()) == 0)
	{
		if (local->flag == 1)
			setpgrp();
		dup2(fd, 0);
		close(fd);
		// get_cmd_name(cmd);
		traverse_cmd(cmd, env, in_fork);
		exit(g_res_exec);
	}
	if (local->flag == 1)
	ft_printf(" %d", pid);
	ljobs_startet("name", local->flag, local->num, pid);
	if (local->flag == 0)
		waitpid(pid, NULL, 0);
}

void			traverse_pipe(t_pipe_sequence *pipe_seq, int fd, char **env,
												int in_fork, t_pjobs *local)
{
	extern char	**environ;
	pid_t		pid;
	int			pipefd[2];

	if (pipe(pipefd) == -1)
		exit(-1);
	if ((pid = fork()) == 0)
	{
		if (local->flag == 1)
			setpgrp();
		close(pipefd[0]);
		dup2(fd, 0);
		dup2(pipefd[1], 1);
		close(pipefd[1]);
		// get_cmd_name(pipe_seq->command->simple_command);
		traverse_cmd(pipe_seq->command->simple_command, environ, in_fork);
		exit(g_res_exec);
	}
	close(pipefd[1]);
	if (local->flag == 1)
		ft_printf(" %d", pid);
	ljobs_startet("name", local->flag, local->num, pid);
	pipe_seq = pipe_seq->next;
	if (pipe_seq->next)
		traverse_pipe(pipe_seq, pipefd[0], environ, in_fork, local);
	else
		handle_last_cmd_in_pipe(pipefd[0], pipe_seq->command->simple_command,
														env, in_fork, local);
	close(pipefd[0]);
	if (local->flag == 0)
		waitpid(pid, NULL, 0);
}
