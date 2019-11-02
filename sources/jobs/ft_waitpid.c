/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_waitpid.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jterry <jterry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 15:36:27 by jterry            #+#    #+#             */
/*   Updated: 2019/11/02 18:46:10 by jterry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"
#include "sem.h"

/*
** Let we have 3 processes in pipe - A, B, C forked from shell process S.
** When A was forked -> sem -2, B -> sem -3, C -> sem -4. (it's `counter').
** In S we do sem -1 to lock shell while A,B,C forking.
** Just before locking last process (C) we do +1 to unlock S.
** Then in S we do +2, +3, +4 to unlock A, B, C.
*/

int				pipe_av(int counter)
{
	int len;

	len = 2;
	reserve_sem(SEMPIPE, 1, 0);
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
			while (job)
			{
				if (waitpid(job->pid, &st, WUNTRACED | WNOHANG) > 0)
					job->done = 1;
				job = job->next;
			}
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
