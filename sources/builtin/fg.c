/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fg.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jterry <jterry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/31 13:58:52 by ggwin-go          #+#    #+#             */
/*   Updated: 2019/09/08 16:58:55 by jterry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

int			fg(t_pjobs *local_job, const char *name)
{
	int			st;
	t_pjobs		*local;
	t_job		*job;
	local = name_proc_hendl(local_job, (char*)name);
	if (local_job == NULL)
	{
		ft_putstr_fd(g_project_name, 2);
		ft_putendl_fd(": fg: Not such job", 2);
		return (1);
	}
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
	waitpid(local->job->pid, &st, 0);
	return (1);
}
