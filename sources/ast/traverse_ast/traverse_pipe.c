/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   traverse_pipe.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggwin-go <ggwin-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 17:26:20 by ggwin-go          #+#    #+#             */
/*   Updated: 2019/10/21 19:44:48 by ggwin-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"
#include "sem.h"

static void		handle_last_cmd_in_pipe(int fd, t_command *cmd, t_pjobs *local,int *counter)
{
	pid_t		pid;

	*counter += 1;
	//printf("increment counter in proc %d (%d)\n", getpid(), *counter);
	if ((pid = fork()) == 0)
	{
		setpgid(getpid(), local->workgpid);
		if (local->workgpid == 0)
			tcsetpgrp(0, getpid());
		//print_error_vaarg ("%d reserve 1 - %d\n", *counter, get_sem(0));
		reserve_sem(SEMPIPE, *counter);
		//print_error_vaarg ("%d reserve 2 - %d\n", *counter, get_sem(0));
		if (fd)
		{
			dup2(fd, 0);
			close(fd);
		}
		if (local->flag == 0)
			tcsetpgrp(0, local->workgpid);
		traverse_command(cmd, 1, local);
		exit(g_res_exec);
	}
	else if (pid == -1)
		print_error_exit("fork error", NULL, 1);
	setpgid(pid, local->workgpid);
	if (local->flag == 1)
		ft_printf(" %d\n", pid);
	local = ljobs_started(get_process_name(cmd), local->flag, local->num, pid);
}

static void		inside_fork(int fd, int pipefd[2], t_pjobs *local,
												t_command *cmd, int *counter)
{
	if (local->workgpid == 0)
	{
		setpgid(getpid(), getpid());
		local->workgpid = getpid();
		tcsetpgrp(0, getpid());
	}
	else
		setpgid(getpid(), local->workgpid);
	//print_error_vaarg ("%d reserve 1 - %d\n", *counter, get_sem(0));
	reserve_sem(SEMPIPE, *counter);
	//print_error_vaarg ("%d reserve 2 - %d\n", *counter, get_sem(0));
	close(pipefd[0]);
	if (fd)
		dup2(fd, 0);
	dup2(pipefd[1], 1);
	close(pipefd[1]);
	if (local->flag == 0)
		tcsetpgrp(0, local->workgpid);
	traverse_command(cmd, 1, local);
	exit(g_res_exec);
}

void			traverse_pipe(t_pipe_sequence *pipe_seq, int fd,
									t_pjobs *local, int *counter)
{
	pid_t		pid;
	int			pipefd[2];

	*counter += 1;
	//printf("increment counter in proc %d (%d)\n", getpid(), *counter);
	if (pipe(pipefd) == -1)
		exit(-1);
	if ((pid = fork()) == 0)
		inside_fork(fd, pipefd, local, pipe_seq->command, counter);
	else if (pid == -1)
		print_error_exit("fork error", NULL, 1);
	if (local->workgpid == 0)
		local->workgpid = pid;
	setpgid(pid, local->workgpid);
	close(pipefd[1]);
	if (local && local->flag == 1)
		ft_printf(" %d", pid);
	local = ljobs_started(get_process_name(pipe_seq->command),
								local->flag, local->num, pid);
	pipe_seq = pipe_seq->next;
	if (pipe_seq->next)
		traverse_pipe(pipe_seq, pipefd[0], local, counter);
	else
		handle_last_cmd_in_pipe(pipefd[0], pipe_seq->command, local, counter);
	close(pipefd[0]);
}
