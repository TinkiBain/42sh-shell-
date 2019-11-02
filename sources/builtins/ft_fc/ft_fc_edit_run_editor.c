/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fc_edit_run_editor.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jterry <jterry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 20:32:41 by gmelisan          #+#    #+#             */
/*   Updated: 2019/11/02 17:29:30 by gmelisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fc.h"

static void	do_some_jobs(pid_t pid, t_pjobs **local)
{
	setpgid(pid, pid);
	if ((*local)->flag == 0)
		tcsetpgrp(0, getpid());
	(*local) = ljobs_started(ft_xstrdup("fc"),
		(*local)->flag, (*local)->num, pid);
	if ((*local)->flag == 0)
		ft_waitpid(pid, NULL);
	else
		g_res_exec = 1;
}

int			ft_fc_edit_run_editor(char **argv, t_pjobs **local)
{
	extern char		**environ;
	pid_t			pid;

	if ((pid = fork()) < 0)
	{
		loginfo("ft_fc(): fork error (%s %s)", argv[0], argv[1]);
		return (1);
	}
	
	if (pid == 0)
	{
		if ((*local)->flag == 1)
			ft_printf("[%d] [%d]\n", (*local)->num, getpid());
		setpgid(getpid(), getpid());
		if ((*local)->flag == 0)
			tcsetpgrp(0, getpid());
		execve(argv[0], argv, environ);
	}
	do_some_jobs(pid, local);
	return (g_res_exec);
}
