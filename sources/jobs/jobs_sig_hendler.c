/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   jobs_sig_hendler.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jterry <jterry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/10 12:44:55 by jterry            #+#    #+#             */
/*   Updated: 2019/09/01 19:45:03 by jterry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

static void			def_kill_or_done(t_pjobs *first, int sig)
{
	if (sig == 9 || sig == 15)
		ft_printf("[%d]\t\t[Killed]\t%s\n", first->num, first->name);
	else
		ft_printf("[%d]\t\t[Done]\t%s\n", first->num, first->name);
	deletejob(&g_pjobs, first->num);
}

void				jobs_sig(void)
{
	t_pjobs			*first;
	pid_t			done_pid;
	int				sig;
	t_job			*job;

	done_pid = 0;
	first = g_pjobs;
	/*if (g_subjob)
	{
		setpgid(g_subjob->job->pid, 0);
		printf ("\n42sh: suspended %s\n", g_subjob->name);
		first = subjob_changer(g_subjob->name, &g_job, 1);
		free(first->status);
		first->status = ft_strdup("\tsuspended\t\t");
		deletejob(&g_subjob, 1);
		return ;
	}*/
	done_pid = waitpid(-1, &sig, WUNTRACED);
	job = job_finder(done_pid, first);
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
