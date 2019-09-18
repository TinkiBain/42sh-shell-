/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bg.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggwin-go <ggwin-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/31 14:00:29 by ggwin-go          #+#    #+#             */
/*   Updated: 2019/09/16 15:37:47 by ggwin-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

int			ft_bg(t_pjobs *local_job, const char *name)
{
	t_pjobs		*local;
	t_job		*job;

	if (local_job)
		local = name_proc_hendl(local_job, (char*)name);
	else
		local = NULL;
	if (local == NULL)
	{
		ft_putstr_fd(g_project_name, 2);
		if (name)
		{
			ft_putstr_fd(": bg: job not found ", 2);
			ft_putendl_fd(name, 2);
		}
		else
			ft_putstr_fd(": bg: no current job\n", 2);
		return (1);
	}
	setpgid(local->workgpid, 0);
	free(local->status);
	local->status = ft_strdup("\t[Running]\t");
	job = local->job;
	while (local->job)
	{
		free(local->job->status);
		kill(local->job->pid, SIGCONT);
		local->job->status = ft_strdup("[Running]");
		local->job = local->job->next;
	}
	local->job = job;
	ft_printf("[%d]\t\t[Continued]\t%s\n", local->num, local->name);
	return (1);
}
