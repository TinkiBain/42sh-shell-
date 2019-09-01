/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bg.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jterry <jterry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/31 14:00:29 by ggwin-go          #+#    #+#             */
/*   Updated: 2019/09/01 18:56:47 by jterry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

void			bg(t_pjobs *local_job, char *name)
{
	t_pjobs		*local;
	local = name_proc_hendl(local_job, name);
	if (local == NULL)
	{
		ft_putstr("Not such job");
		return ;
	}
	setpgid(local->workgpid, 0);
	free(local->status);
	local->status = ft_strdup("\t[Running]\t");
	while (local->job)
	{
		free(local->job->status);
		local->job->status = ft_strdup("[Running]");
		local->job = local->job->next;
	}
	/*
	** отправлять всем саб джобам сигналы о продолжение или только одному
	*/
	kill(local->job->pid, SIGCONT);
	ft_printf("[%d]\t[Continued]\t%s\n", local->num, local->name);
}
