/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bg.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jterry <jterry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/31 14:00:29 by ggwin-go          #+#    #+#             */
/*   Updated: 2019/10/09 17:18:46 by gmelisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

int			bg_null_error(const char *name)
{
	if (name)
		print_error_vaarg("bg: %s: job not found\n", name);
	else
		print_error("bg", "no current job");
	return (1);
}

int			ft_bg(t_pjobs *local_job, const char *name)
{
	t_pjobs		*local;
	t_job		*job;

	if (local_job)
		local = name_proc_hendl(local_job, (char*)name);
	else
		local = NULL;
	if (local == NULL)
		return (bg_null_error(name));
	setpgid(local->workgpid, 0);
	free(local->status);
	local->status = ft_xstrdup(" running\t\t");
	job = local->job;
	while (local->job)
	{
		free(local->job->status);
		kill(local->job->pid, SIGCONT);
		local->job->status = ft_xstrdup(" running\t\t");
		local->job = local->job->next;
	}
	local->job = job;
	ft_printf("[%d]\t\t[Continued]\t%s\n", local->num, local->name);
	return (1);
}
