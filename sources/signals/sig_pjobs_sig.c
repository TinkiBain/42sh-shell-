/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sig_pjobs_sig.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jterry <jterry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 17:28:50 by jterry            #+#    #+#             */
/*   Updated: 2019/10/23 23:04:04 by jterry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

static void		def_kill_or_done(t_job *first, int sig, char *name)
{
	char *msg;

	if ((msg = that_sig(sig, g_pjobs->name)))
	{
		ft_printf("[%d]\t%s\n", first->num, msg);
		free(msg);
	}
	else if (sig != 2)
	{
		if (sig == 0 || sig == 256)
			ft_printf("[%d]\tDone  \t\t%s\n", first->num, name);
		else
			ft_printf("[%d]\tExit %d\t\t%s\n", first->num, sig, name);
	}
	deletejob(&g_pjobs, first->num);
}

void			pjobs_sig(int st, int done_pid, int del)
{
	t_pjobs			*first;
	t_job			*job;
	char			*msg;

	msg = NULL;
	job = NULL;
	first = job_finder(done_pid, g_pjobs);
	if (first == NULL)
		return ;
	job = process_finder(done_pid, first);
	if (done_pid != 0 && !(WIFSTOPPED(st)) && del)
		def_kill_or_done(job, st, first->name);
	if (!job->done)
	{
		free(job->status);
		if (st == SUSPINT || st == SUSPOUT)
		{
			if (st == SUSPINT)
				job->status = ft_xstrdup("\tsuspended (tty input)\t");
			else if (st == SUSPOUT)
				job->status = ft_xstrdup("\tsuspended (tty output)\t");
			else
				job->status = ft_xstrdup(" suspended \t\t");
		}
		free(first->status);
		first->status = ft_xstrdup("suspended");
	}
}
