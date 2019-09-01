/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals_hendler.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggwin-go <ggwin-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/01 16:10:32 by jterry            #+#    #+#             */
<<<<<<< Updated upstream
/*   Updated: 2019/09/01 20:32:22 by ggwin-go         ###   ########.fr       */
=======
/*   Updated: 2019/09/01 19:54:02 by jterry           ###   ########.fr       */
>>>>>>> Stashed changes
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
		write(1, "\n", 1);
}

void		signal_monitor(void)
{
	signal(SIGCHLD, signals);
	signal(SIGTSTP, signals);
	signal(SIGTTOU, signals);
}
