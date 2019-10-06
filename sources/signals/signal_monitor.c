/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_monitor.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jterry <jterry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/01 16:10:32 by jterry            #+#    #+#             */
/*   Updated: 2019/10/02 22:00:06 by jterry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

static void	signals(int signo)
{
	if (signo == SIGCHLD)
		jobs_sig();
	if (signo == SIGTTOU)
		tcsetpgrp(0, getpid());
	if (signo == SIGTTIN)
		tcsetpgrp(1, getpid());
	if (signo == SIGTSTP)
		write(1, "\n", 0);
	if (signo == SIGINT)
		write(1, "\n", 1);
}

void		signal_monitor(void)
{
	signal(SIGCONT, signals);
	signal(SIGCHLD, signals);
	signal(SIGTSTP, signals);
	signal(SIGTTOU, signals);
	signal(SIGPIPE, signals);
	signal(SIGINT, signals);
}
