/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sig_main_handler.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jterry <jterry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/10 12:44:55 by jterry            #+#    #+#             */
/*   Updated: 2019/10/15 19:05:09 by jterry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"
#include <errno.h>

static void		pipe_and_done_pid(int done_pid)
{
	int i;

	i = 0;
	if (g_pipe_pid)
	{
		while (g_pipe_pid[i] != 0)
		{
			if (g_pipe_pid[i] == done_pid)
			{
				g_pipe_pid[i] = -1;
				return ;
			}
			i++;
		}
	}
}

static int		pipe_jobs_check(void)
{
	int i;

	i = 0;
	if (g_pipe_pid)
	{
		while (g_pipe_pid[i] != 0)
		{
			if (g_pipe_pid[i] == -1)
				return (1);
			i++;
		}
	}
	return (-1);
}

static void		msg_cntr(int st)
{
	char *msg;

	msg = NULL;
	if ((msg = that_sig(st, g_subjob->name)))
		print_error(NULL, msg);
	if (msg)
		free(msg);
}

extern int errno;

void			jobs_sig(void)
{
	pid_t			done_pid;
	int				st;
	char			*msg;

	msg = NULL;
	st = 0;
	done_pid = waitpid(-1, &st, WUNTRACED | WNOHANG);
	if (g_pipe_pid)
		pipe_and_done_pid(done_pid);
	g_wait_flags = done_pid;
	if (WIFEXITED(st))
		g_res_exec = WEXITSTATUS(st);
	tcsetpgrp(0, getpid());
	if (WIFSTOPPED(st))
	{
		return (sig_per_stop(done_pid, NULL, ft_xstrdup("  suspended\t"),
							g_pjobs));
	}
	else if (g_subjob && pid_checl(done_pid, g_subjob->job))
	{
		msg_cntr(st);
		if (pipe_jobs_check() > 0)
			deletejob(&g_subjob, g_subjob->num);
		return ;
	}
	pjobs_sig(st, done_pid);
}
