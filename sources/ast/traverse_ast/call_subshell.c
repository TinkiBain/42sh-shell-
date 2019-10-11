/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   call_subshell.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jterry <jterry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 14:06:19 by ggwin-go          #+#    #+#             */
/*   Updated: 2019/10/11 14:35:19 by jterry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

int					call_subshell(char *str, t_pjobs *local)
{
	extern t_opt	g_opt;
	extern char		**environ;
	pid_t			pid;

	if ((pid = fork()) == 0)
	{
		if (local->flag == 1)
			setpgrp();
		g_opt.is_subshell = 1;
		g_opt.is_single_cmd = 1;
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
