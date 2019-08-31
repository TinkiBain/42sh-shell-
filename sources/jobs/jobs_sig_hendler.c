/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   j_sig_hendler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jterry <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/10 12:44:55 by jterry            #+#    #+#             */
/*   Updated: 2019/08/26 15:19:26 by jterry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void			print(t_jobs *job, char *str)
{
	ft_putendl_nb("[", 1);
	ft_putendl_nb(job->str_num, 1);
	ft_putendl_nb("]\t", 1);
	ft_putendl_nb(str, 1);
	ft_putendl_nb(job->name, 1);
	ft_putendl_nb("\n", 1);
}

static void			def_kill_or_done(t_jobs *first, int sig)
{
	if (first)
	{
		if (sig == 9 || sig == 15)
			print(first, "\t\t[Killed]\t");
		else
			print(first, "\t\t[Done]\t\t");
	}
	deletejob(&joba, first->num);
}

void				jobs_sig(void)
{
	t_jobs			*first;
	pid_t			done_pid;
	int				sig;

	done_pid = 0;
	first = joba;
	done_pid = waitpid(-1, &sig, WUNTRACED);
	while (first && first->PID != done_pid)
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
