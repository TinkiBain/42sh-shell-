/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sig_pjobs_sig.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jterry <jterry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 17:28:50 by jterry            #+#    #+#             */
/*   Updated: 2019/10/14 17:45:13 by jterry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

static void		def_kill_or_done(t_job *first, int sig)
{
	char *msg;

	if ((msg = that_sig(sig, g_pjobs->name)))
	{
		ft_printf("[%d]\t%s\n", first->num, msg);
		free(msg);
	}
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

void			pjobs_sig(int sig, int done_pid)
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
