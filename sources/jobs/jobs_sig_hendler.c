/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   jobs_sig_hendler.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jterry <jterry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/10 12:44:55 by jterry            #+#    #+#             */
/*   Updated: 2019/09/07 20:18:14 by jterry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

static void			def_kill_or_done(t_pjobs *first, int sig)
{
	if (sig == 9 || sig == 15)
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
	if (g_subjob && pid_checl(done_pid, g_subjob->job))
	{
		g_wait_flags = done_pid;
		if (sig == 4735)
		{
			setpgid(g_subjob->job->pid, 0);
			ft_printf ("\n42sh: suspended %s\n", g_subjob->name);
			first = subjob_changer(g_subjob->name, &g_pjobs, 1);
			free(first->status);
			first->status = ft_strdup("\tsuspended\t\t");
		}
		deletejob(&g_subjob, g_subjob->num);
		return ;
	}
	job = job_finder(done_pid, g_pjobs);
	first = jobs_find_num(g_pjobs, job->num);
	if (job == NULL)
		return ;
	if (done_pid != 0 && sig != 5503 && sig != 5759)
		def_kill_or_done(first, sig);
	if (sig == 5503 || sig == 5759)
	{
		free(first->status);
		if (sig == 5503)
			first->status = ft_strdup("\tsuspended (tty input)\t");
		if (sig == 5759)
			first->status = ft_strdup("\tsuspended (tty output)\t");
	}
}
