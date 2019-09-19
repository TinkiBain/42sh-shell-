/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fg.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jterry <jterry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/31 13:58:52 by ggwin-go          #+#    #+#             */
/*   Updated: 2019/09/16 19:07:50 by jterry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

int			fg_null_error(const char *name)
{
	ft_putstr_fd(g_project_name, 2);
	if (name)
	{
		ft_putstr_fd(": fg: job not found ", 2);
		ft_putendl_fd(name, 2);
	}
	else
		ft_putstr_fd(": fg: no current job\n", 2);
	return (1);
}

int			ft_fg(t_pjobs *local_job, const char *name)
{
	t_pjobs		*local;
	t_job		*job;

	if (local_job)
		local = name_proc_hendl(local_job, (char*)name);
	else
		local = NULL;
	if (local == NULL)
		return (fg_null_error(name));
	free(local->status);
	local->status = ft_strdup("\t[Running]\t");
	tcsetpgrp(0, local->workgpid);
	job = local->job;
	while (local->job)
	{
		free(local->job->status);
		kill(local->job->pid, SIGCONT);
		local->job->status = ft_strdup("[Running]");
		local->job = local->job->next;
	}
	local->job = job;
	if (local->job->next)
		pipe_av(local->job);
	ft_waitpid(local->job->pid);
	return (pid_fredy());
}