/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_waitpid.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jterry <jterry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 15:36:27 by jterry            #+#    #+#             */
/*   Updated: 2019/09/20 15:31:39 by jterry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

int		pipe_av(t_job *job)
{
	int i;

	g_pipe_pid = (int*)ft_xmalloc(sizeof(int) * 100);
	i = 0;
	while (job)
	{
		g_pipe_pid[i] = job->pid;
		kill(g_pipe_pid[i], SIGCONT);
		job = job->next;
		i++;
	}
	g_wait_flags = 0;
	g_pipe_pid[i] = 0;
	return (1);
}

int		ft_waitpid(pid_t pid)
{
	int i;

	i = 0;
	while (42)
	{
		if (g_pipe_pid)
		{
			i = 0;
			while (g_pipe_pid[i] != 0)
			{
				if ((g_pipe_pid[i] != 0) && (g_pipe_pid[i] == g_wait_flags))
					return (1);
				i++;
			}
		}
		if (g_wait_flags == pid)
		{
			g_wait_flags = 0;
			return (1);
		}
	}
}
