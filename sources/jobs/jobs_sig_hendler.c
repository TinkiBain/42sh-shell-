/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   jobs_sig_hendler.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggwin-go <ggwin-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/10 12:44:55 by jterry            #+#    #+#             */
/*   Updated: 2019/08/31 14:20:19 by ggwin-go         ###   ########.fr       */
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
