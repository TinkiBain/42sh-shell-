/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_waitpid.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jterry <jterry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 15:36:27 by jterry            #+#    #+#             */
/*   Updated: 2019/10/13 19:14:12 by jterry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"
#include "sem.h"

int				pipe_av(t_job *job, int counter)
{
	int		i;
	int		len;
	t_job	*tjob;

	tjob = job;
	len = 0;
	while (tjob)
	{
		len++;
		tjob = tjob->next;
	}
	g_pipe_pid = (int*)ft_xmalloc(sizeof(int) * (len + 1));
	i = 0;
	while (i < len)
	{
		g_pipe_pid[i] = job->pid;
		job = job->next;
		i++;
	}
	g_wait_flags = 0;
	g_pipe_pid[i] = 0;
	i = 0;
	//ft_printf("\nC=%d\n", get_sem());
	release_sem(counter);
	//ft_printf("\nC2=%d\n", get_sem());
	return (1);
}

static void		zero()
{
	int i;

	i = -1;
	while (g_pipe_pid[++i])
		g_pipe_pid[i] = 0;
}

static int		t(int len)
{
	int	t_len;
	int st;

	st = 0;
	t_len = 0;
	while (t_len < len)
	{
		if (g_pipe_pid[t_len] != -1)
		{
			t_len = 0;
			continue ;
		}
		t_len++;
	}
	zero();
	free(g_pipe_pid);
	return (1);
}

int				ft_waitpid(pid_t pid)
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
			if (t(len) > 0)
				return (1);
	}
	return (1234);
}
