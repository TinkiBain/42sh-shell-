/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   jobs_sig_hendler.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jterry <jterry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/10 12:44:55 by jterry            #+#    #+#             */
/*   Updated: 2019/09/20 15:10:59 by jterry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

static void			def_kill_or_done(t_job *first, int sig)
{
	if (!first->next)
	{
		if (sig == SIGKILL || sig == SIGTERM)
			ft_printf("[%d]\tTerminatede\t%s\n", first->num, first->name);
		else
			ft_printf("[%d]\tExit %d\t\t%s\n", first->num, sig, first->name);
		if (g_pjobs->workgpid != 0)
			deletejob(&g_pjobs, first->num);
	}
	else
	{
		free(first->status);
		first->status = ft_strdup("Done\t\t");
	}
}

static void			sigstop(void)
{
	t_pjobs			*first;
	t_job			*job;

	job = NULL;
	setpgid(g_subjob->job->pid, 0);
	ft_printf("\n42sh: suspended %s\n", g_subjob->name);
	first = subjob_changer(g_subjob->name, &g_pjobs, 1);
	first->job = g_subjob->job;
	g_subjob->job = NULL;
	free(first->status);
	first->status = ft_strdup(" suspended\t");
	job = first->job;
	while (job)
	{
		free(job->status);
		job->status = ft_strdup(" suspended\t");
		job = job->next;
	}
}

static void			sig_per_stop(int done_pid, t_job *job)
{
	t_pjobs			*first;

	first = g_pjobs;
	while (first)
	{
		if ((job = pid_checl(done_pid, first->job)))
		{
			ft_printf("\n42sh: suspended %s\n",
				jobs_find_num(first, job->num)->name);
			break ;
		}
		first = first->next;
	}
	while (job)
	{
		free(job->status);
		job->status = ft_strdup(" suspended\t");
		job = job->next;
	}
	if (g_subjob && pid_checl(done_pid, g_subjob->job))
	{
		sigstop();
		if (g_subjob->workgpid == 0)
			deletejob(&g_subjob, g_subjob->num);
	}
}

static void			pjobs_sig(int sig, int done_pid)
{
	t_pjobs			*first;
	t_job			*job;

	job = NULL;
	job = job_finder(done_pid, g_pjobs);
	if (job == NULL)
		return ;
	first = jobs_find_num(g_pjobs, job->num);
	if (done_pid != 0 && sig != SUSPINT && sig != SUSPOUT)
		def_kill_or_done(first->job, sig);
	else if (sig == SUSPINT || sig == SUSPOUT)
	{
		free(first->status);
		if (sig == SUSPINT)
			first->status = ft_strdup("\tsuspended (tty input)\t");
		if (sig == SUSPOUT)
			first->status = ft_strdup("\tsuspended (tty output)\t");
		free(job->status);
		job->status = ft_xstrdup("suspended");
	}
}

void				jobs_sig(void)
{
	pid_t			done_pid;
	int				sig;
	t_job			*job;

	job = NULL;
	sig = 0;
	done_pid = waitpid(-1, &sig, WUNTRACED);
	g_res_exec = sig;
	g_wait_flags = done_pid;
	if (WIFEXITED(g_res_exec))
		g_res_exec = WEXITSTATUS(g_res_exec);
	set_result();
	if (sig == SUSPCHLD)
	{
		sig_per_stop(done_pid, NULL);
		return ;
	}
	else if (g_subjob && pid_checl(done_pid, g_subjob->job))
	{
		if (g_subjob->workgpid == 0)
			deletejob(&g_subjob, g_subjob->num);
		return ;
	}
	pjobs_sig(sig, done_pid);
}
