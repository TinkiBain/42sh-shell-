/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sig_main_handler.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelisan <gmelisan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/10 12:44:55 by jterry            #+#    #+#             */
/*   Updated: 2019/10/13 17:00:13 by gmelisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

static void		pipe_and_done_pid(int done_pid)
{
	int i;

	i = 0;
	printf ("AAA\n");
	if (g_pipe_pid)
	{
		while (g_pipe_pid[i] != 0)
		{
			printf ("..%d %d\n", g_pipe_pid[i], done_pid );
			if (g_pipe_pid[i] == done_pid)
			{
				printf ("..%d\n", g_pipe_pid[i] );
				g_pipe_pid[i] = -1;
				printf ("..%d\n", g_pipe_pid[i]);
				return ;
			}
			i++;
		}
	}
}

/*static void			zero()
{
	int i;

	i = -1;
	while (g_pipe_pid[++i])
		g_pipe_pid[i] = 0;
}*/

static int		pipe_jobs_check(void)
{
	int i;

	i = 0;
	if (g_pipe_pid)
	{
		while (g_pipe_pid[i] != 0)
		{
			if (g_pipe_pid[i] == -1)
			{
				//zero();
				free(g_pipe_pid);
				return (1);
			}
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

void			jobs_sig(void)
{
	pid_t			done_pid;
	int				st;
	char			*msg;

	msg = NULL;
	st = 0;
	//sleep(1);
	done_pid = waitpid(-1, &st, WUNTRACED | WNOHANG);
	printf ("++%d\n", st);
	if (g_pipe_pid)
		pipe_and_done_pid(done_pid);
	g_wait_flags = done_pid;
	if (WIFEXITED(st))
		g_res_exec = WEXITSTATUS(st);
	if (WIFSTOPPED(st))
	{
		sig_per_stop(done_pid, NULL, ft_xstrdup("  suspended\t"));
		return ;
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
