/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bg.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jterry <jterry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/31 14:00:29 by ggwin-go          #+#    #+#             */
/*   Updated: 2019/10/14 18:01:42 by jterry           ###   ########.fr       */
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

void		ft_bg_part(t_pjobs *local, int *pids, int iter)
{
	t_job		*job;

	job = local->job;
	ft_printf("[%d]\tcontinued\t%s\n", local->num, local->name);
	while (local->job)
	{
		pids[iter++] = local->job->pid;
		free(local->job->status);
		local->job->status = ft_xstrdup(" running\t\t");
		local->job = local->job->next;
	}
	local->job = job;
	iter = -1;
	while (pids[++iter])
		kill(pids[iter], SIGCONT);
}

int			ft_bg(t_pjobs *local_job, const char *name)
{
	t_pjobs		*local;
	int			pids[100];
	int			iter;

	iter = 0;
	while (iter < 100)
		pids[iter++] = 0;
	iter = 0;
	if (local_job)
		local = name_proc_hendl(local_job, (char*)name);
	else
		local = NULL;
	if (local == NULL)
		return (bg_null_error(name));
	setpgid(local->workgpid, 0);
	free(local->status);
	local->status = ft_xstrdup(" running\t\t");
	ft_bg_part(local, pids, iter);
	return (1);
}
