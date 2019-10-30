/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sig_stop_kind.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jterry <jterry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 17:21:21 by jterry            #+#    #+#             */
/*   Updated: 2019/10/30 22:51:00 by jterry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

static void		sigstop(char *msg)
{
	t_pjobs		*first;
	t_job		*job;

	job = NULL;
	setpgid(g_subjob->job->pid, 0);
	ft_printf("\n42sh: %s\t%s\n", msg, g_subjob->name);
	first = subjob_changer(ft_xstrdup(g_subjob->name), &g_pjobs, 0);
	first->job = g_subjob->job;
	g_subjob->job = NULL;
	free(first->status);
	first->status = ft_xstrdup(msg);
	job = first->job;
	while (job)
	{
		if (!job->done)
		{
			free(job->status);
			job->status = ft_xstrdup(msg);
		}
		job = job->next;
	}
}

static void		sig_change_status(t_job *job, char *msg)
{
	while (job)
	{
		if (!job->done)
		{
			job->done = 2;
			kill(job->pid, SIGTSTP);
			free(job->status);
			job->status = ft_xstrdup(msg);
		}
		job = job->next;
	}
}

void			sig_per_stop(int done_pid, t_job *job,
								char *msg, t_pjobs *first)
{
	while (first)
	{
		if ((job = process_finder(done_pid, job_finder(done_pid, first))))
		{
			first = jobs_find_num(first, job->num);
			if (ft_strcmp(job->status, msg))
				ft_printf("\n42sh: %s%s\n", msg,
					jobs_find_num(first, job->num)->name);
			free(first->status);
			first->status = ft_xstrdup(msg);
			sig_change_status(job, msg);
			break ;
		}
		first = first->next;
	}
	if (g_subjob && (job = process_finder(done_pid,
					job_finder(done_pid, g_subjob))))
	{
		sigstop(msg);
		sig_change_status(job, msg);
		deletejob(&g_subjob, g_subjob->num);
	}
	g_is_interrupt = 1;
	free(msg);
}
