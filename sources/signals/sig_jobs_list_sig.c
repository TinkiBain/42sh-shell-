/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sig_jobs_list_sig.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jterry <jterry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 17:28:50 by jterry            #+#    #+#             */
/*   Updated: 2019/11/02 15:22:09 by jterry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

extern t_opt g_opt;

#define NONNORMEXIT 256

static void		def_kill_or_done(t_job *first, int sig, char *name, int num)
{
	char *msg;

	if ((msg = that_sig(sig, first->name)))
	{
		ft_printf("[%d]\t%s\n", num, msg);
		free(msg);
	}
	else if (sig != SIGINT && !g_opt.is_subshell)
	{
		if ((sig == 0 || sig == NONNORMEXIT))
			ft_printf("[%d]\tDone  \t\t%s\n", num, name);
		else
			ft_printf("[%d]\tExit %d\t\t%s\n", num, sig, name);
	}
	deletejob(&g_jobs_list, num);
}

static void		pjobs_sig(int st, int done_pid, int del)
{
	t_pjobs		*first;
	t_job		*job;

	if ((first = job_finder(done_pid, g_jobs_list)) == NULL)
		return ;
	job = process_finder(done_pid, first);
	if (done_pid != 0 && !(WIFSTOPPED(st)) && del)
		def_kill_or_done(job, st, first->name, first->num);
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

static void		sub_job_handler(int st, t_job *job)
{
	msg_cntr(st);
	if (job)
	{
		job->done = 1;
		if (st == 0 || st == 256)
		{
			free(job->status);
			job->status = ft_xstrdup("\tDone\t\t");
		}
		if (pipe_jobs_check(g_cur_job->job) > 0)
			deletejob(&g_cur_job, g_cur_job->num);
	}
	return ;
}

void			not_stop_sig(int st, int done_pid)
{
	t_job			*job;

	job = NULL;
	if (g_cur_job && (job = process_finder(done_pid, g_cur_job)))
	{
		sub_job_handler(st, job);
		return ;
	}
	else
	{
		job = process_finder(done_pid, job_finder(done_pid, g_jobs_list));
		if (!job)
		{
			g_res_exec = 1;
			ft_exit(0, NULL);
		}
		job->done = 1;
		if (that_sig(st, NULL))
		{
			free(job->status);
			job->status = that_sig(st, NULL);
		}
	}
	if (pipe_jobs_check(job_finder(done_pid, g_jobs_list)->job) > 0)
		pjobs_sig(st, done_pid, 1);
	else
		pjobs_sig(st, done_pid, 0);
}
