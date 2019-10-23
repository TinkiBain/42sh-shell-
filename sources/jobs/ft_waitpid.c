/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_waitpid.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jterry <jterry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 15:36:27 by jterry            #+#    #+#             */
/*   Updated: 2019/10/23 22:15:23 by jterry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"
#include "sem.h"

int				pipe_av(int counter)
{
	int len;

	len = 2;
	reserve_sem(SEMPIPE, 1);
	while (len <= counter)
	{
		// print_error_vaarg ("after release(%d) - %d\n", len, get_sem(0));
		release_sem(SEMPIPE, len);
		// print_error_vaarg ("befor release(%d) - %d\n", len, get_sem(0));
		len++;
	}
	return (1);
}

static int		pipe_all_pids_check(t_job *local)
{
	int st;
	int pid;
	t_job *job;

	job = local;
	pid = 0;
	st = 0;
	while (job)
	{
		if (!job->done)
		{
			if ((pid = waitpid(job->pid, &st, WUNTRACED | WNOHANG | WCONTINUED)) > 0)
				job->done = 1;
			job = local;
			continue ;
		}
		job = job->next;
	}
	return (1);
}

int				ft_waitpid(pid_t pid, t_job *local)
{
	int i;


	i = 0;
	if (!(local))
	{
		while (42)
		{
			if (g_wait_flags == pid)
			{
				tcsetpgrp(0, getpid());
				g_wait_flags = 0;
				return (1);
			}
		}
	}
	else
	{
		while (42)
			if (pipe_all_pids_check(local) > 0)
			{
				tcsetpgrp(0, getpid());
				return (1);
			}
	}
	return (1234);
}
