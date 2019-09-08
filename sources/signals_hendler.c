/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals_hendler.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jterry <jterry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/01 16:10:32 by jterry            #+#    #+#             */
/*   Updated: 2019/09/08 16:34:39 by jterry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

static void	signals(int signo)
{
	if (signo == SIGCHLD && (g_pjobs || g_subjob))
		jobs_sig();
	if (signo == SIGTTOU)
		tcsetpgrp(9, getpid());
	if (signo == SIGTSTP)
		write(1, "\n", 0);
}

void		signal_monitor(void)
{
	signal(SIGCHLD, signals);
	signal(SIGTSTP, signals);
	signal(SIGTTOU, signals);
}
