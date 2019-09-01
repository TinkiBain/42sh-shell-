/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   jobs_sig_hendler.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jterry <jterry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/10 12:44:55 by jterry            #+#    #+#             */
/*   Updated: 2019/09/01 15:36:50 by jterry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

static void			def_kill_or_done(t_jobs *first, int sig)
{
	if (first)
	{
		if (sig == 9 || sig == 15)
			ft_printf("[%s]\t\t[Killed]\t%s\n", first->str_num, first->name);
		else
			ft_printf("[%s]\t\t[Done]\t%s\n", first->str_num, first->name);
	}
	deletejob(&g_jobs, first->num);
}

void				jobs_sig(void)
{
	t_jobs			*first;
	pid_t			done_pid;
	int				sig;

	done_pid = 0;
	first = g_jobs;
	if (g_subjob)
	{
		setpgid(g_subjob->pid, 0);
		printf ("\n42sh: suspended %s\n", g_subjob->name);
		first = subjob_changer(g_subjob->name, &g_jobs, 1);
		free(first->status);
		first->status = ft_strdup("\tsuspended\t\t");
		deletejob(&g_subjob, 1);
		return ;
	}
	done_pid = waitpid(-1, &sig, WUNTRACED);
	while (first && first->pid != done_pid)
		first = first->next;
	if (first == NULL)
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
