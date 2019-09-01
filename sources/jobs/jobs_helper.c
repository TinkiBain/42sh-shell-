/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   jobs_helper.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jterry <jterry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/01 19:22:32 by jterry            #+#    #+#             */
/*   Updated: 2019/09/01 19:47:25 by jterry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

t_job		*job_finder(int pid, t_pjobs *local)
{
	while (local)
	{
		while (local->job)
		{
			if (local->job->pid == pid)
				return (local->job);
			local->job = local->job->next;
		}
		local = local->next;
	}
	return (NULL);
}
