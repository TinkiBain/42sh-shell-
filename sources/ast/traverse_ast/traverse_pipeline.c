/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   traverse_pipeline.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwisoky <dwisoky@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/05 21:16:42 by ggwin-go          #+#    #+#             */
/*   Updated: 2019/08/26 14:05:53 by dwisoky          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

extern char	**g_var;

static void		handle_last_cmd_in_pipe(int fd, t_cmd *cmd, char **env,
															int in_fork)
{
	pid_t		pid2;

	if ((pid2 = fork()) == 0)
	{
		dup2(fd, 0);
		close(fd);
		traverse_cmd(cmd, env, in_fork);
		exit(g_res_exec);
	}
	waitpid(pid2, &g_res_exec, 0);
}

static void		ast_handle_pipe(t_pipe_sequence *pipe_seq, int fd, char **env,
															int in_fork)
{
	extern char	**environ;
	pid_t		pid;
	int			pipefd[2];

	if (pipe(pipefd) == -1)
		exit(-1);
	if ((pid = fork()) == 0)
	{
		close(pipefd[0]);
		dup2(fd, 0);
		dup2(pipefd[1], 1);
		close(pipefd[1]);
		traverse_cmd(pipe_seq->cmd, environ, in_fork);
		exit(g_res_exec);
	}
	close(pipefd[1]);
	pipe_seq = pipe_seq->next;
	if (pipe_seq->pipe_op)
		ast_handle_pipe(pipe_seq, pipefd[0], environ, in_fork);
	else
		handle_last_cmd_in_pipe(pipefd[0], pipe_seq->cmd, env, in_fork);
	close(pipefd[0]);
	waitpid(pid, NULL, 0);
}

static char		*get_cmd_name(t_cmd *cmd)
{
	if (cmd->cmd_pref)
	{
		if (cmd->cmd_word)
		{
			cmd->cmd_word = tdq(cmd->cmd_word);
			return (cmd->cmd_word);
		}
	}
	else
	{
		cmd->cmd_name = tdq(cmd->cmd_name);
		return (cmd->cmd_name);
	}
	return (NULL);
}

static void		pipe_sequence_iter(t_pipe_sequence *pipe_seq, char **env)
{
	pid_t		pid;
	char		*cmd_name;
	int			flag;

	if (pipe_seq->pipe_op)
		ast_handle_pipe(pipe_seq, 0, env, 1);
	else
	{
		if ((cmd_name = get_cmd_name(pipe_seq->cmd)))
		{
			if (is_builtin(cmd_name))
				traverse_cmd(pipe_seq->cmd, env, 0);
			else if ((flag = check_cmd(cmd_name)) == 0)
			{
				hash_add_count(cmd_name);
				if ((pid = fork()) == 0)
					traverse_cmd(pipe_seq->cmd, env, 1);
				else
					waitpid(pid, &g_res_exec, 0);
			}
		}
		else
			traverse_cmd(pipe_seq->cmd, env, 1);
	}
}

void			traverse_pipeline(t_pipeline *root)
{
	extern char	**environ;

	if (root->pipe_sequence)
	{
		pipe_sequence_iter(root->pipe_sequence, environ);
		if (root->bang)
			g_res_exec = (!g_res_exec) ? 1 : 0;
	}
}
