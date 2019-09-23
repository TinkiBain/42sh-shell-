/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   traverse_pipe.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggwin-go <ggwin-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 17:26:20 by ggwin-go          #+#    #+#             */
/*   Updated: 2019/09/23 20:58:09 by ggwin-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

static void		handle_last_cmd_in_pipe(int fd, t_command *cmd, t_pjobs *local)
{
	pid_t		pid;
	// char		*str;

	redir_set();
	// str = get_process_name(cmd);
	traverse_redirections(cmd);
	if ((pid = fork()) == 0)
	{
		if (local->flag == 1)
			setpgrp();
		dup2(fd, 0);
		close(fd);
		raise(SIGSTOP);
		traverse_command(cmd, 1, local);
		// execute_line(str);
		exit(g_res_exec);
	}
	redir_reset();
	if (local->flag == 1)
		ft_printf(" %d\n", pid);
	local = ljobs_startet(get_process_name(cmd), local->flag, local->num, pid);
	pipe_av(local->job);
}

void			traverse_pipe(t_pipe_sequence *pipe_seq, int fd, t_pjobs *local)
{
	pid_t		pid;
	int			pipefd[2];
	// char		*str;

	redir_set();
	// str = get_process_name(pipe_seq->command);
	traverse_redirections(pipe_seq->command);
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
		raise(SIGSTOP);
		// execute_line(str);
		traverse_command(pipe_seq->command, 1, local);
		exit(g_res_exec);
	}
	redir_reset();
	close(pipefd[1]);
	if (local && local->flag == 1)
		ft_printf(" %d", pid);
	local = ljobs_startet(get_process_name(pipe_seq->command), local->flag, local->num, pid);
	pipe_seq = pipe_seq->next;
	if (pipe_seq->next)
		traverse_pipe(pipe_seq, pipefd[0], local);
	else
		handle_last_cmd_in_pipe(pipefd[0], pipe_seq->command, local);
	close(pipefd[0]);
}
