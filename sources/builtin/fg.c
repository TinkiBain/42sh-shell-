/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fg.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggwin-go <ggwin-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/31 13:58:52 by ggwin-go          #+#    #+#             */
/*   Updated: 2019/08/31 14:20:19 by ggwin-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

void			fg(t_jobs *local_job, char *name)
{
	int			st;

	if (name && name[1])
		while (local_job)
		{
			if (!ft_strcmp(local_job->name, name)
					|| !ft_strcmp(local_job->str_num, &name[1]))
				break ;
			local_job = local_job->next;
		}
	else
		local_job = jobs_last_elem(local_job);
	if (local_job == NULL)
	{
		ft_putstr("Not such job");
		return ;
	}
	tcsetpgrp(0, local_job->pid);
	kill(local_job->pid, SIGCONT);
	free(local_job->status);
	local_job->status = ft_strdup("[Running]");
	waitpid(local_job->pid, &st, 0);
}
