/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sig_monitor.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jterry <jterry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/01 16:10:32 by jterry            #+#    #+#             */
/*   Updated: 2019/10/14 01:14:41 by jterry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

static void	sigh_exit(int signo)
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

/*
**	loginfo("Caught signal %d", signo);
*/

static void	signals(int signo)
{
	extern t_line	*g_line;

	if (signo == SIGCHLD)
		jobs_sig();
	else if (signo == SIGTTOU)
		tcsetpgrp(0, getpid());
	else if (signo == SIGTTIN)
		tcsetpgrp(1, getpid());
	else if (signo == SIGINT)
		ft_putstr("\n");
	else if (signo == SIGTERM)
		reset_line(g_line);
}

static void	signal_sigwinch(int signo)
{
	extern t_opt	g_opt;

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
	signal(SIGQUIT, signals);
	signal(SIGCONT, signals);
	signal(SIGCHLD, signals);
	signal(SIGTSTP, signals);
	signal(SIGTTOU, signals);
	signal(SIGPIPE, signals);
	signal(SIGTTIN, signals);
	signal(SIGINT, signals);
	signal(SIGTERM, signals);
	signal(SIGSEGV, sigh_exit);
	signal(SIGABRT, sigh_exit);
	signal(SIGWINCH, signal_sigwinch);
}
