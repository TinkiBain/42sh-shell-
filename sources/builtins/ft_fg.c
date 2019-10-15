/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fg.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jterry <jterry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/31 13:58:52 by ggwin-go          #+#    #+#             */
/*   Updated: 2019/10/15 19:30:33 by jterry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

int			fg_null_error(const char *name)
{
	if (name)
		print_error_vaarg("fg: %s: job not found\n", name);
	else
		print_error("fg", "no current job");
	return (1);
}

void		closer(t_job *job, int counter, int *pids)
{
	pipe_av(job, counter);
	killpg(job->pid, SIGCONT);
	tcsetpgrp(0, job->pid);
	if (job->next)
		ft_waitpid(-1);
	else
		ft_waitpid(pids[0]);
}

void		ft_fg_part(t_pjobs *local, int *pids, int iter)
{
	t_job		*job;
	int			counter;

	counter = 0;
	job = local->job;
	while (local->job)
	{
		pids[iter++] = local->job->pid;
		counter++;
		free(local->job->status);
		local->job->status = ft_xstrdup("  running\t\t");
		local->job = local->job->next;
	}
	local->job = job;
	closer(job, counter, pids);
}

int			ft_fg(t_pjobs *local_job, const char *name)
{
	t_pjobs		*local;
	int			pids[100];
	int			iter;

	iter = 0;
	while (iter < 100)
		pids[iter++] = 0;
	iter = 0;
	if (local_job)
		local = name_proc_hendl(local_job, (char*)name);
	else
		local = NULL;
	if (local == NULL)
		return (fg_null_error(name));
	free(local->status);
	local->status = ft_xstrdup("  running\t\t");
	ft_fg_part(local, pids, iter);
	return (0);
}
