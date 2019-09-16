/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   traverse_pipe_sequence.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jterry <jterry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 19:46:45 by ggwin-go          #+#    #+#             */
/*   Updated: 2019/09/16 17:08:18 by jterry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

extern char	**g_var;

static void	pipe_seq_simple_builtin(t_command *cmd, char **env, t_pjobs *local)
{
	pid_t	pid;

	if (local->flag == 0)
	{
		deletejob(&g_subjob, g_subjob->num);
		traverse_command(cmd, env, 0, local);
	}
	else if (local->flag == 1)
	{
		if ((pid = fork()) == 0)
		{
			setpgrp();
			traverse_command(cmd, env, 0, local);
			exit(g_res_exec);
		}
		else
		{
			ljobs_startet(get_subjob_name(cmd), local->flag, local->num, pid);
			ft_printf("[%d] [%d]\n", local->num, pid);
			ft_waitpid(pid);
		}
	}
}

static void	pipe_seq_simple_non_builtin(t_command *cmd,
								char **env, t_pjobs *local, char *cmd_name)
{
	pid_t	pid;

	hash_add_count(cmd_name);
	if ((pid = fork()) == 0)
	{
		if (local->flag == 1)
			setpgrp();
		traverse_command(cmd, env, 1, local);
	}
	else
	{
		ljobs_startet(get_subjob_name(cmd), local->flag, local->num, pid);
		if (local->flag == 0)
			ft_waitpid(pid);
		else
			ft_printf("[%d] [%d]\n", local->num, pid);
	}
}

static void	traverse_pipe_seq_without_pipe(t_command *cmd, char **env,
											t_pjobs *local)
{
	char	*cmd_name;

	traverse_redirections(cmd);
	if (cmd->simple_command)
	{
		cmd->simple_command->cmd_name = tdq(cmd->simple_command->cmd_name);
		if ((cmd_name = cmd->simple_command->cmd_name))
		{
			if (is_builtin(cmd_name))
				pipe_seq_simple_builtin(cmd, env, local);
			else if (check_cmd(cmd_name) == 0)
				pipe_seq_simple_non_builtin(cmd, env, local, cmd_name);
			else
			{
				if (local->flag == 0)
					deletejob(&g_subjob, g_subjob->num);
				else
					deletejob(&g_pjobs, local->num);
			}
		}
		else
			traverse_command(cmd, env, 0, local);
	}
	else
		traverse_command(cmd, env, 0, local);
}

void		traverse_pipe_sequence(t_pipe_sequence *pipe_seq, char **env,
															t_pjobs *local)
{
	if (pipe_seq->next)
	{
		if (local->flag == 1)
			ft_printf("[%d]", local->num);
		traverse_pipe(pipe_seq, 0, env, 1, local);
	}
	else
		traverse_pipe_seq_without_pipe(pipe_seq->command, env, local);
}
