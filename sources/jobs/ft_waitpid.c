/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_waitpid.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jterry <jterry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 15:36:27 by jterry            #+#    #+#             */
/*   Updated: 2019/10/25 19:35:05 by jterry           ###   ########.fr       */
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
		release_sem(SEMPIPE, len);
		len++;
	}
	return (1);
}

static int		pipe_all_pids_check(t_job *local)
{
	int		st;
	t_job	*job;

	job = local;
	st = 0;
	while (job)
	{
		if (!job->done)
		{
			if (waitpid(job->pid, &st, WUNTRACED | WNOHANG) > 0)
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
				g_wait_flags = 0;
				return (1);
			}
		}
	}
	else
	{
		while (42)
			if (pipe_all_pids_check(local) > 0)
				return (1);
	}
	return (1234);
}
