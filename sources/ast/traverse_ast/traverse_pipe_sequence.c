/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   traverse_pipe_sequence.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jterry <jterry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 19:46:45 by ggwin-go          #+#    #+#             */
/*   Updated: 2019/10/11 17:21:13 by jterry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

extern char			**g_var;

int					pid_fredy(void)
{
	int				i;

	i = -1;
	if (g_pipe_pid)
	{
		while (g_pipe_pid[++i] != 0)
			g_pipe_pid[i] = 0;
		free(g_pipe_pid);
		g_pipe_pid = NULL;
	}
	g_wait_flags = 0;
	return (1);
}

static void			pipe_seq_simple_builtin(t_command *cmd, t_pjobs *local)
{
	pid_t			pid;

	if (local->flag == 0)
		traverse_command(cmd, 0, local);
	else if (local->flag == 1)
	{
		if ((pid = fork()) == 0)
		{
			setpgrp();
			traverse_command(cmd, 0, local);
			exit(g_res_exec);
		}
		else
		{
			local = ljobs_startet(get_process_name(cmd), local->flag,
														local->num, pid);
			ft_printf("[%d] [%d]\n", local->num, pid);
		}
	}
}

static void			pipe_seq_simple_non_builtin(t_command *cmd, t_pjobs *local,
																char *cmd_name)
{
	extern t_opt	g_opt;
	pid_t			pid;

	hash_add_count(cmd_name);
	if (g_opt.is_subshell && g_opt.is_single_cmd)
		return (traverse_command(cmd, 1, local));
	if ((pid = fork()) == 0)
	{
		if (local->flag == 1)
			setpgrp();
		traverse_command(cmd, 1, local);
	}
	else
	{
		local = ljobs_startet(get_process_name(cmd), local->flag,
													local->num, pid);
		if (local->flag == 1)
			ft_printf("[%d] [%d]\n", local->num, pid);
		else
			ft_waitpid(pid);
	}
}

static void			pipe_seq_without_pipe(t_command *cmd, t_pjobs *local)
{
	char			*cmd_name;


	if (traverse_redirections(cmd) == -1)
		return ;
	if (cmd->simple_command)
	{
		cmd->simple_command->cmd_name = tdq(cmd->simple_command->cmd_name);
		if ((cmd_name = cmd->simple_command->cmd_name))
		{
			if (is_builtin(cmd_name))
				pipe_seq_simple_builtin(cmd, local);
			else if (check_cmd(cmd_name) == 0)
				pipe_seq_simple_non_builtin(cmd, local, cmd_name);
			else if (local->job)
				freedsubjob(&local->job);
		}
		else
			traverse_command(cmd, 0, local);
	}
	else
		traverse_command(cmd, 0, local);
	if (cmd->simple_command)
		redir_reset();
}

void				traverse_pipe_sequence(t_pipe_sequence *pipe_seq,
														t_pjobs *local)
{
	if (pipe_seq->next)
	{
		if (local->flag == 1)
			ft_printf("[%d]", local->num);
		traverse_pipe(pipe_seq, 0, local);
		if (local->flag == 0)
			ft_waitpid(-1);
		pid_fredy();
	}
	else
		pipe_seq_without_pipe(pipe_seq->command, local);
}
