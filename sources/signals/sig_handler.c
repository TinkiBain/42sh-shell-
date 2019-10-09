/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sig_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jterry <jterry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/10 12:44:55 by jterry            #+#    #+#             */
/*   Updated: 2019/10/09 14:28:56 by gmelisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

static void			def_kill_or_done(t_job *first, int sig)
{
	char *msg;

	if ((msg = that_sig(sig, g_pjobs->name)))
		ft_printf("[%d]\t%s\n", first->num, msg);
	else
		ft_printf("[%d]\tExit %d\t\t%s\n", first->num, sig, first->name);
	if (g_pjobs->workgpid == 0 || !(first->next))
		deletejob(&g_pjobs, first->num);
	else
	{
		free(first->status);
		first->status = ft_xstrdup("Done\t\t");
	}
}

static void			sigstop(char *msg)
{
	t_pjobs			*first;
	t_job			*job;

	job = NULL;
	setpgid(g_subjob->job->pid, 0);
	ft_printf("\n42sh: %s %s\n", msg, g_subjob->name);
	first = subjob_changer(ft_xstrdup(g_subjob->name), &g_pjobs, 0);
	first->job = g_subjob->job;
	g_subjob->job = NULL;
	free(first->status);
	first->status = ft_xstrdup(msg);
	job = first->job;
	while (job)
	{
		free(job->status);
		job->status = ft_xstrdup(msg);
		job = job->next;
	}
}

static void			sig_per_stop(int done_pid, t_job *job, char *msg)
{
	t_pjobs			*first;

	first = g_pjobs;
	while (first)
	{
		if ((pid_checl(done_pid, first->job)))
		{
			job = first->job;
			if (ft_strcmp(job->status, msg))
				ft_printf("\n42sh: %s %s\n", msg, jobs_find_num(first, job->num)->name);
			free (first->status);
			first->status = ft_xstrdup(msg);
			while (job)
			{
				free (job->status);
				job->status = ft_xstrdup(msg);
				job = job->next;
			}
			break ;
		}
		first = first->next;
	}
	while (job)
	{
		free(job->status);
		job->status = ft_xstrdup(msg);
		job = job->next;
	}
	if (g_subjob && pid_checl(done_pid, g_subjob->job))
	{
		sigstop(msg);
		if (g_subjob->workgpid == 0)
			deletejob(&g_subjob, g_subjob->num);
	}
	free(msg);
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
			first->status = ft_xstrdup(" suspended (tty input)\t");
		if (sig == SUSPOUT)
			first->status = ft_xstrdup(" suspended (tty output)\t");
		free(job->status);
		job->status = ft_xstrdup("suspended");
	}
}

void g(int f)
{
	int i;

	i = 0;
	if (g_pipe_pid)
	{
		while (g_pipe_pid[i] != 0)
		{
			if (g_pipe_pid[i] ==  f)
			{
				g_pipe_pid[i] = -1;
				return ;
			}
			i++;
		}
	}
}

int taa(void)
{
	int i;

	i = 0;
	if (g_pipe_pid)
	{
		while (g_pipe_pid[i] != 0)
		{
			if (g_pipe_pid[i] != -1)
				return (-1);
			i++;
		}
	}
	return (1);
}

void				jobs_sig(void)
{
	pid_t			done_pid;
	int				st;
	t_job			*job;
	char			*msg;

	msg = NULL;
	job = NULL;
	st = 0;
	done_pid = waitpid(-1, &st, WUNTRACED | WNOHANG);
	//ft_putnbr_fd(done_pid,2);
	//printf("waitpid %d\n", done_pid);
	if (g_pipe_pid)
		g(done_pid);
	g_res_exec = st;
	g_wait_flags = done_pid;
	//printf ("%d %d %d %d\n", WTERMSIG(st), st, WIFSTOPPED(st), WSTOPSIG(st));
	if (WIFEXITED(g_res_exec))
		g_res_exec = WEXITSTATUS(g_res_exec);
	if (WIFSTOPPED(st))
	{
		sig_per_stop(done_pid, NULL, ft_strdup("  suspended\t"));
		return ;
	}
	else if (g_subjob && pid_checl(done_pid, g_subjob->job))
	{
		if ((msg = that_sig(st, g_subjob->name)))
			print_error("jobs_sig()", msg);
		if (g_subjob->workgpid == 0 && taa() > 0)
			deletejob(&g_subjob, g_subjob->num);
		return ;
	}
	pjobs_sig(st, done_pid);
}
