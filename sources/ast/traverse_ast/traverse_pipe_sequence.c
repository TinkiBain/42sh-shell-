/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   traverse_pipe_sequence.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggwin-go <ggwin-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 19:46:45 by ggwin-go          #+#    #+#             */
/*   Updated: 2019/09/10 18:19:06 by ggwin-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

extern char	**g_var;

static void	pipe_seq_simple_builtin(t_pipe_sequence *pipe_seq,
											char **env, t_pjobs *local)
{
	pid_t	pid;

	if (local->flag == 0)
	{
		deletejob(&g_subjob, g_subjob->num);
		traverse_command(pipe_seq->command, env, 0);
	}
	else if (local->flag == 1)
	{
		if ((pid = fork()) == 0)
		{
			setpgrp();
			traverse_command(pipe_seq->command, env, 0);
			exit(g_res_exec);
		}
		else
		{
			waitpid(pid, NULL, 0);
			ft_printf("[%d] [%d]\n", local->num, pid);
		}
	}
}

static void	pipe_seq_simple_non_builtin(t_pipe_sequence *pipe_seq,
								char **env, t_pjobs *local, char *cmd_name)
{
	pid_t	pid;

	hash_add_count(cmd_name);
	if ((pid = fork()) == 0)
	{
		if (local->flag == 1)
			setpgrp();
		traverse_command(pipe_seq->command, env, 1);
	}
	else
	{
		ljobs_startet("name", local->flag, local->num, pid);
		if (local->flag == 0)
			waitpid(pid, NULL, 0);
		else
			ft_printf("[%d] [%d]\n", local->num, pid);
	}
}

void		traverse_pipe_sequence(t_pipe_sequence *pipe_seq, char **env,
															t_pjobs *local)
{
	char	*cmd_name;
	int		flag;

	if (pipe_seq->next)
	{
		if (local->flag == 1)
			ft_printf("[%d]", local->num);
		traverse_pipe(pipe_seq, 0, env, 1, local);
		if (local->flag == 1)
			ft_printf("\n");
	}
	else
	{
		if ((cmd_name = get_cmd_name(pipe_seq->command->simple_command)))
		{
			if (is_builtin(cmd_name))
				pipe_seq_simple_builtin(pipe_seq, env, local);
			else if ((flag = check_cmd(cmd_name)) == 0)
				pipe_seq_simple_non_builtin(pipe_seq, env, local, cmd_name);
			else
			{
				if (local->flag == 0)
					deletejob(&g_subjob, g_subjob->num);
				else
					deletejob(&g_pjobs, local->num);
			}
		}
		else
			traverse_command(pipe_seq->command, env, 1);
	}
}
