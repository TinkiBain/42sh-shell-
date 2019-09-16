/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_waitpid.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jterry <jterry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 15:36:27 by jterry            #+#    #+#             */
/*   Updated: 2019/09/16 19:06:15 by jterry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

int		pipe_av(t_job *job)
{
	int i;

	g_pipe_pid = (char**)ft_xmalloc(sizeof(char*) * 100);
	i = 0;
	while (job)
	{
		g_pipe_pid[i] = ft_itoa(job->pid);
		job = job->next;
		i++;
	}
	g_pipe_pid[i] = NULL;
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
			while (g_pipe_pid[i])
			{
				if (ft_atoi(g_pipe_pid[i]) &&
					((ft_atoi(g_pipe_pid[i]) == g_wait_flags)))
				{
					g_wait_flags = 0;
					return (1);
				}
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
