/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fg.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jterry <jterry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/31 13:58:52 by ggwin-go          #+#    #+#             */
/*   Updated: 2019/09/01 18:56:52 by jterry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

void			fg(t_pjobs *local_job, char *name)
{
	int			st;

	t_pjobs		*local;
	local = name_proc_hendl(local_job, name);
	if (local_job == NULL)
	{
		ft_putstr("Not such job");
		return ;
	}
	free(local->status);
	local->status = ft_strdup("\t[Running]\t");
	tcsetpgrp(0, local->workgpid);
	while (local->job)
	{
		free(local_job->job->status);
		local->job->status = ft_strdup("[Running]");
		local->job = local->job->next;
	}
	/*
	** отправлять всем саб джобам сигналы о продолжение или только одному
	*/
	kill(local->job->pid, SIGCONT);
	waitpid(local->job->pid, &st, 0);
}
