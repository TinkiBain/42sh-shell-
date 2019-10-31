/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   traverse_pipe.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggwin-go <ggwin-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 17:26:20 by ggwin-go          #+#    #+#             */
/*   Updated: 2019/10/31 15:16:45 by ggwin-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"
#include "sem.h"

static void		handle_last_cmd_in_pipe(int fd, t_command *cmd,
												t_pjobs **local, int *counter)
{
	pid_t		pid;

	*counter += 1;
	if ((pid = fork()) == 0)
	{
		setpgid(getpid(), (*local)->workgpid);
		dup2(fd, 0);
		close(fd);
		release_sem(SEMPIPE, 1);
		reserve_sem(SEMPIPE, *counter, 0);
		traverse_command(cmd, 1, local);
		exit(g_res_exec);
	}
	else if (pid == -1)
		print_error_exit("fork error", NULL, 1);
	setpgid(pid, (*local)->workgpid);
	if ((*local)->flag == 1)
		ft_printf(" %d\n", pid);
	(*local) = ljobs_started(get_process_name(cmd), (*local)->flag,
													(*local)->num, pid);
}

static void		inside_fork(int fd, int pipefd[2], t_pjobs **local,
													int *counter)
{
	setpgid(getpid(), (*local)->workgpid);
	close(pipefd[0]);
	if (fd)
		dup2(fd, 0);
	dup2(pipefd[1], 1);
	close(pipefd[1]);
	if (fd == 0 && (*local)->flag == 0)
		tcsetpgrp(0, getpid());
	reserve_sem(SEMPIPE, *counter, 0);
}

static void		handle_job(char *str, t_pjobs **local, pid_t pid)
{
	if ((*local) && (*local)->flag == 1)
		ft_printf(" %d", pid);
	(*local) = ljobs_started(str, (*local)->flag, (*local)->num, pid);
}

void			traverse_pipe(t_pipe_sequence *pipe_seq, int fd,
									t_pjobs **local, int *counter)
{
	pid_t		pid;
	int			pipefd[2];

	*counter += 1;
	if (pipe(pipefd) == -1)
		exit(-1);
	pid = fork();
	if ((*local)->workgpid == 0)
		(*local)->workgpid = pid;
	if (pid == 0)
	{
		inside_fork(fd, pipefd, local, counter);
		traverse_command(pipe_seq->command, 1, local);
		exit(g_res_exec);
	}
	else if (pid == -1)
		print_error_exit("fork error", NULL, 1);
	setpgid(pid, (*local)->workgpid);
	close(pipefd[1]);
	handle_job(get_process_name(pipe_seq->command), local, pid);
	if ((pipe_seq = pipe_seq->next)->next)
		traverse_pipe(pipe_seq, pipefd[0], local, counter);
	else
		handle_last_cmd_in_pipe(pipefd[0], pipe_seq->command, local, counter);
	close(pipefd[0]);
}
