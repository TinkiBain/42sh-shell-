/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_monitor.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelisan <gmelisan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/27 19:06:18 by gmelisan          #+#    #+#             */
/*   Updated: 2019/09/27 19:07:50 by gmelisan         ###   ########.fr       */
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
	if (signo == SIGPIPE)
		ft_printf("Phiv\n");	/* ?? */
}

void		signal_monitor(void)
{
	signal(SIGCHLD, signals);
	signal(SIGTSTP, signals);
	signal(SIGTTOU, signals);
	signal(SIGPIPE, signals);
}
