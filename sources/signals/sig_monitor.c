/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sig_monitor.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggwin-go <ggwin-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/01 16:10:32 by jterry            #+#    #+#             */
/*   Updated: 2019/10/27 17:57:16 by ggwin-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

extern t_opt g_opt;

void		sigh_exit(int signo)
{
	term_restore();
	ft_putchar('\n');
	loginfo_backtrace();
	if (signo == SIGSEGV)
		print_error_exit("fatal", "Segmentation fault", 1);
	else if (signo == SIGABRT)
		print_error_exit("fatal", "Aborted", 1);
	else
		print_error_exit(NULL, "Fatal error", 1);
}

extern int	g_term_broken;

static void	signals(int signo)
{
	extern t_line	*g_line;
	int				st;

	st = 0;
	if (signo == SIGCHLD)
		jobs_sig(st);
	else if (signo == SIGTTOU)
		tcsetpgrp(1, getpid());
	else if (signo == SIGTTIN)
		tcsetpgrp(0, getpid());
	else if (signo == SIGINT && tcgetpgrp(0) != getpid())
		ft_putstr("\n");
	else if (signo == SIGTERM)
		reset_line(g_line);
}

int			g_cont_flag;

static void	sig_cont_standart(int signo)
{
	t_pjobs			*childs;
	t_job			*job;

	signo = 0;
	childs = g_pjobs;
	while (childs)
	{
		job = childs->job;
		while (job)
		{
			kill(job->pid, SIGCONT);
			job = job->next;
		}
		childs = childs->next;
	}
	childs = g_subjob;
	while (childs)
	{
		job = childs->job;
		while (job)
		{
			kill(job->pid, SIGCONT);
			job = job->next;
		}
		childs = childs->next;
	}
	g_cont_flag = 1;
}

static void	signal_sigwinch(int signo)
{
	if (signo == SIGWINCH)
	{
		loginfo("SIGWINCH caught: [%dx%d]",
				get_screen_width(), get_screen_height());
		if (g_opt.vi_mode || g_opt.emacs_mode)
			update_line(NULL, 0);
	}
}

void		signal_monitor(void)
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
	signal(SIGQUIT, signals);
	signal(SIGCHLD, signals);
	signal(SIGTTOU, signals);
	signal(SIGPIPE, signals);
	signal(SIGTTIN, signals);
	signal(SIGINT, signals);
	signal(SIGTERM, signals);
	signal(SIGALRM, sigh_exit);
	signal(SIGSEGV, sigh_exit);
	signal(SIGABRT, sigh_exit);
	signal(SIGWINCH, signal_sigwinch);
}
