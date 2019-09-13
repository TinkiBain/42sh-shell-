/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   jobs_helper.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jterry <jterry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/01 19:22:32 by jterry            #+#    #+#             */
/*   Updated: 2019/09/13 21:01:21 by jterry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

t_job		*job_finder(int pid, t_pjobs *local)
{
	t_job *h;

	while (local)
	{
		h = local->job;
		while (local->job)
		{
			if (local->job->pid == pid)
				return (local->job);
			local->job = local->job->next;
		}
		local->job = h;
		local = local->next;
	}
	return (NULL);
}

t_pjobs		*jobs_find_num(t_pjobs *local, int num)
{
	int		high;

	if (num == 0)
		high = find_highnum(local);
	else
		high = num;
	while (local && local->num != high)
		local = local->next;
	return (local);
}

t_job		*pid_checl(int pid, t_job *job)
{
	while (job)
	{
		if (job->pid == pid)
			return (job);
		job = job->next;
	}
	return (NULL);
}
