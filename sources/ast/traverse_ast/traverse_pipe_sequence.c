/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   traverse_pipe_sequence.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jterry <jterry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 19:46:45 by ggwin-go          #+#    #+#             */
/*   Updated: 2019/10/13 17:41:27 by jterry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

extern char			**g_var;

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
	int counter;

	counter = 0;
	if (pipe_seq->next)
	{
		if (local->flag == 1)
			ft_printf("[%d]", local->num);
		traverse_pipe(pipe_seq, 0, local, &counter);
		pipe_av(local->job, counter + 1);
		if (local->flag == 0)
			ft_waitpid(-1);
	}
	else
		pipe_seq_without_pipe(pipe_seq->command, local);
}
