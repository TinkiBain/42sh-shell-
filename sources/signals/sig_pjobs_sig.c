/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sig_pjobs_sig.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jterry <jterry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 17:28:50 by jterry            #+#    #+#             */
/*   Updated: 2019/11/01 19:47:10 by jterry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

extern t_opt g_opt;

#define NONNORMEXIT 256

static void		def_kill_or_done(t_job *first, int sig, char *name)
{
	char *msg;

	if ((msg = that_sig(sig, first->name)))
	{
		ft_printf("[%d]\t%s\n", first->num, msg);
		free(msg);
	}
	else if (sig != SIGINT && !g_opt.is_subshell)
	{
		if ((sig == 0 || sig == NONNORMEXIT))
			ft_printf("[%d]\tDone  \t\t%s\n", first->num, name);
		else
			ft_printf("[%d]\tExit %d\t\t%s\n", first->num, sig, name);
	}
	deletejob(&g_pjobs, first->num);
}

static void		pjobs_sig(int st, int done_pid, int del)
{
	t_pjobs			*first;
	t_job			*job;

	first = job_finder(done_pid, g_pjobs);
	if (first == NULL)
		return ;
	job = process_finder(done_pid, first);
	if (done_pid != 0 && !(WIFSTOPPED(st)) && del)
		def_kill_or_done(job, st, first->name);
	else if (!job->done)
	{
		free(job->status);
		if (st == SUSPINT || st == SUSPOUT)
		{
			if (st == SUSPINT)
				job->status = ft_xstrdup("\tsuspended (tty input)\t");
			else if (st == SUSPOUT)
				job->status = ft_xstrdup("\tsuspended (tty output)\t");
			else
				job->status = ft_xstrdup("\tsuspended \t\t");
		}
		else
			job->status = ft_xstrdup("\tsuspended \t\t");		
		free(first->status);
		first->status = ft_xstrdup("\tsuspended\t\t");
	}
}

static void		sub_job_handler(int st, t_job *job, int done_pid)
{
	msg_cntr(st);
	if ((job = process_finder(done_pid, g_subjob)))
	{
		job->done = 1;
		if (st == 0 || st == 256)
		{
			free(job->status);
			job->status = ft_xstrdup("\tDone\t\t");
		}
		if (pipe_jobs_check(g_subjob->job) > 0)
			deletejob(&g_subjob, g_subjob->num);
	}
	return ;
}

void			not_stop_sig(int st, int done_pid)
{
	t_job			*job;

	job = NULL;
	if (g_subjob && process_finder(done_pid, g_subjob))
	{
		sub_job_handler(st, job, done_pid);
		return ;
	}
	else
	{
		job = process_finder(done_pid, job_finder(done_pid, g_pjobs));
		job->done = 1;
		if (that_sig(st, NULL))
		{
			free(job->status);
			job->status = that_sig(st, NULL);
		}
	}
	if (pipe_jobs_check(job_finder(done_pid, g_pjobs)->job) > 0)
		pjobs_sig(st, done_pid, 1);
	else
		pjobs_sig(st, done_pid, 0);
}
