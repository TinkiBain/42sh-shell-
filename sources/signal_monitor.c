/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_monitor.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jterry <jterry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/01 16:10:32 by jterry            #+#    #+#             */
/*   Updated: 2019/09/28 21:33:04 by jterry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

static void	signals(int signo)
{
	if (signo == SIGCHLD)
		jobs_sig();
	if (signo == SIGTTOU)
		tcsetpgrp(9, getpid());
	if (signo == SIGTSTP)
		write(1, "\n", 0);
	if (signo == SIGINT)
		write(1, "\n", 1);
}

void		signal_monitor(void)
{
	signal(SIGCHLD, signals);
	signal(SIGTSTP, signals);
	signal(SIGTTOU, signals);
	signal(SIGPIPE, signals);
	signal(SIGINT, signals);
}
