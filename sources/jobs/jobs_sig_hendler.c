/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   jobs_sig_hendler.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jterry <jterry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/10 12:44:55 by jterry            #+#    #+#             */
/*   Updated: 2019/09/12 19:14:48 by jterry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

static void			def_kill_or_done(t_pjobs *first, int sig)
{
	if (sig == SIGKILL || sig == SIGTERM)
		ft_printf("[%d]\t\t[Killed]\t\t%s\n", first->num, first->name);
	else
		ft_printf("[%d]\t\t[Done]\t\t%s\n", first->num, first->name);
	deletejob(&g_pjobs, first->num);
}

static t_job			*pid_checl(int pid, t_job *job)
{
	while (job)
	{
		if (job->pid == pid)
			return (job);
		job = job->next;
	}
	return (NULL);
}

void				jobs_sig(void)
{
	t_pjobs			*first;
	pid_t			done_pid;
	int				sig;
	t_job			*job;

	done_pid = 0;
	sig = 0;
	done_pid = waitpid(-1, &sig, WUNTRACED);
	g_res_exec = sig;
	g_wait_flags = done_pid;
	if (WIFEXITED(g_res_exec))
		g_res_exec = WEXITSTATUS(g_res_exec);
	set_result();
	if (g_subjob && pid_checl(done_pid, g_subjob->job))
	{
		if (sig == SUSPCHLD)
		{
			setpgid(g_subjob->job->pid, 0);
			ft_printf ("\n42sh: suspended %s\n", g_subjob->name);
			first = subjob_changer(g_subjob->name, &g_pjobs, 1);
			first->job = g_subjob->job;
			g_subjob->job = NULL;
			free(first->status);
			first->status = ft_strdup("\tsuspended\t\t");
		}
		deletejob(&g_subjob, g_subjob->num);
		return ;
	}
	job = job_finder(done_pid, g_pjobs);
	if (job == NULL)
		return ;
	first = jobs_find_num(g_pjobs, job->num);
	if (done_pid != 0 && sig != SUSPINT && sig != SUSPOUT)
		def_kill_or_done(first, sig);
	if (sig == SUSPINT || sig == SUSPOUT)
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
