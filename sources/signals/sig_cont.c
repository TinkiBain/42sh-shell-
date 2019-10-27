/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sig_cont.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jterry <jterry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/27 18:35:43 by jterry            #+#    #+#             */
/*   Updated: 2019/10/27 18:42:43 by jterry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

extern int				g_cont_flag;

static void	sender_sig(t_job *job)
{
	while (job)
	{
		kill(job->pid, SIGCONT);
		job = job->next;
	}
}

static void	sig_cont_standart(int signo)
{
	t_pjobs			*childs;
	t_job			*job;

	signo = 0;
	childs = g_pjobs;
	while (childs)
	{
		job = childs->job;
		sender_sig(job);
		childs = childs->next;
	}
	childs = g_subjob;
	while (childs)
	{
		job = childs->job;
		sender_sig(job);
		childs = childs->next;
	}
	g_cont_flag = 1;
}

void		cont_sig_handler(void)
{
	struct sigaction new_action;
	struct sigaction old_action;

	bzero(&new_action, sizeof(new_action));
	bzero(&old_action, sizeof(old_action));
	new_action.sa_handler = sig_cont_standart;
	if (g_cont_flag == 0)
	{
		sigaction(SIGCONT, &new_action, &old_action);
		if (g_cont_flag == 1)
			raise(SIGCONT);
	}
	else
	{
		sigaction(SIGCONT, &old_action, NULL);
		g_cont_flag = 0;
	}
}
