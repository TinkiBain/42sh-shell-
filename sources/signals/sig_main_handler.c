/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sig_main_handler.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jterry <jterry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/10 12:44:55 by jterry            #+#    #+#             */
/*   Updated: 2019/10/25 19:32:35 by jterry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

/*
** Return 1 or 0 if all process in main_job is ended
*/

int				pipe_jobs_check(t_job *main_job)
{
	t_job *job;

	job = main_job;
	while (job)
	{
		if (!job->done)
			return (-1);
		job = job->next;
	}
	return (1);
}

/*
** This func print msg about shild status
*/

void			msg_cntr(int st)
{
	char *msg;

	msg = NULL;
	if ((msg = that_sig(st, g_subjob->name)))
		print_error(NULL, msg);
	if (msg)
		free(msg);
}

char			*st_sif(int st)
{
	if (st == SUSTOP)
		return (ft_strdup("\tstoped\t"));
	else if (st == SUSPCHLD)
		return (ft_strdup("\tsuspended\t"));
	else if (st == SUSPOUT)
		return (ft_strdup("\tsuspended (tty output)\t"));
	else if (st == SUSPINT)
		return (ft_strdup("\tsuspended (tty input)\t"));
	return (ft_strdup("\tsuspended\t"));
}

void			jobs_sig(int st)
{
	pid_t			done_pid;
	char			*msg;

	msg = NULL;
	done_pid = waitpid(-1, &st, WUNTRACED | WNOHANG | WCONTINUED);
	if (done_pid <= 0)
		return ;
	g_wait_flags = done_pid;
	if (WIFEXITED(st))
		g_res_exec = WEXITSTATUS(st);
	if (WIFSTOPPED(st))
	{
		if (st == SUSPCHLD)
			g_res_exec = 1;
		return (sig_per_stop(done_pid, NULL, st_sif(st), g_pjobs));
	}
	not_stop_sig(st, done_pid);
}
