/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   call_subshell.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggwin-go <ggwin-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 14:06:19 by ggwin-go          #+#    #+#             */
/*   Updated: 2019/10/08 15:58:01 by ggwin-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

int			call_subshell(char *str, t_pjobs *local)
{
	pid_t		pid;
	extern char	**environ;
	extern int	g_subshell_without_fork;

	if ((pid = fork()) == 0)
	{
		if (local->flag == 1)
			setpgrp();
		g_subshell_without_fork = 1;
		execute_line(str);
		exit(g_res_exec);
	}
	local = ljobs_startet(str, local->flag, local->num, pid);
	if (local->flag == 1)
		ft_printf("[%d] [%d]\n", local->num, pid);
	else
		ft_waitpid(pid);
	return (0);
}
