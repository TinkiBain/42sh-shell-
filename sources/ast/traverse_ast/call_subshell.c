/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   call_subshell.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwisoky <dwisoky@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 14:06:19 by ggwin-go          #+#    #+#             */
/*   Updated: 2019/10/30 19:35:53 by dwisoky          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

extern t_opt		g_opt;

void				call_subshell(char *str, t_pjobs **local)
{
	extern char		**environ;
	pid_t			pid;

	if (g_opt.is_subshell && g_opt.is_single_cmd)
	{
		execute_line(str);
		exit(g_res_exec);
	}
	if ((pid = fork()) == 0)
	{
		setpgrp();
		if ((*local)->flag == 0)
			tcsetpgrp(0, getpid());
		g_opt.is_subshell = 1;
		g_opt.is_single_cmd = 1;
		execute_line(str);
		exit(g_res_exec);
	}
	else if (pid == -1)
		print_error_exit("fork error", NULL, 1);
	(*local) = ljobs_started(str, (*local)->flag, (*local)->num, pid);
	if ((*local)->flag == 1)
		ft_printf("[%d] [%d]\n", (*local)->num, pid);
	else
		ft_waitpid(pid, NULL);
}
