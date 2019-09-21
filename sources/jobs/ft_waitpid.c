/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_waitpid.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jterry <jterry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 15:36:27 by jterry            #+#    #+#             */
/*   Updated: 2019/09/21 21:07:37 by jterry           ###   ########.fr       */
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
		job = job->next;
		i++;
	}
	g_wait_flags = 0;
	g_pipe_pid[i] = 0;
	i = 0;
	while (g_pipe_pid[i])
		kill(g_pipe_pid[i++], SIGCONT);
	return (1);
}

int t(int len)
{
	int st;
	int	t_len;

	t_len = 0;
	st = 0;
	while (t_len < len)
	{
		if (g_pipe_pid[t_len] != -1)
		{
			if (waitpid(g_pipe_pid[t_len], &st, WNOHANG | WUNTRACED) > 0)
				g_pipe_pid[t_len] = -1;
		//	printf ("AAAA %d\n", waitpid(g_pipe_pid[t_len], &st, WNOHANG | WUNTRACED));
		//	sleep(1);
			return (-1);
		}
		t_len++;
	}
	return (1);
}

int		ft_waitpid(pid_t pid)
{
	int len;
	int i;

	len = 0;
	if (g_pipe_pid)
		while (g_pipe_pid[len])
			len++;
	i = 0;
	if (pid > 0)
	{
		while (42)
			if (g_wait_flags == pid)
			{
				g_wait_flags = 0;
				return (1);
			}
	}
	else if (pid <= 0)
	{
		while (42)
		{
			if (t(len) > 0)
				return (1);
		}
	}
	return (1234);
}
