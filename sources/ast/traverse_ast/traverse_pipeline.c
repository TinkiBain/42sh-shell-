/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   traverse_pipeline.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggwin-go <ggwin-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/05 21:16:42 by ggwin-go          #+#    #+#             */
/*   Updated: 2019/08/06 17:40:26 by ggwin-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

static void	handle_last_cmd_in_pipe(int fd, t_cmd *cmd)
{
	pid_t		pid2;

	if ((pid2 = fork()) == 0)
	{
		dup2(fd, 0);
		close(fd);
		traverse_cmd(cmd);
	}
	waitpid(pid2, &g_res_exec, 0);
}

static void	ast_handle_pipe(t_pipe_sequence *pipe_seq, int fd)
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
		traverse_cmd(pipe_seq->cmd);
	}
	else
	{
		close(pipefd[1]);
		pipe_seq = pipe_seq->next;
		if (pipe_seq->pipe_op)
			ast_handle_pipe(pipe_seq, pipefd[0]);
		else
			handle_last_cmd_in_pipe(pipefd[0], pipe_seq->cmd);
		close(pipefd[0]);
	}
	waitpid(pid, NULL, 0);
}

static char	*get_cmd_name(t_cmd *cmd)
{
	if (cmd->cmd_pref)
	{
		if (cmd->cmd_word)
			return (cmd->cmd_word);
	}
	else
		return (cmd->cmd_name);
	return (NULL);
}

static void	pipe_sequence_iter(t_pipe_sequence *pipe_seq)
{
	pid_t		pid;
	char		*cmd_name;

	if (pipe_seq->pipe_op)
	{
		ast_handle_pipe(pipe_seq, 0);
	}
	else
	{
		if ((cmd_name = get_cmd_name(pipe_seq->cmd)))
		{
			if (check_builtin(cmd_name))
			{
				// redir_set();
				traverse_cmd(pipe_seq->cmd);
				// redir_reset();
			}
			else
			{
				if ((pid = fork()) == 0)
					traverse_cmd(pipe_seq->cmd);
				else
					waitpid(pid, &g_res_exec, 0);
			}
		}
	}
}

void	traverse_pipeline(t_pipeline *root)
{
	if (root->pipe_sequence)
	{
		pipe_sequence_iter(root->pipe_sequence);
		if (root->bang)
			g_res_exec = (!g_res_exec) ? 1 : 0;
	}
}
