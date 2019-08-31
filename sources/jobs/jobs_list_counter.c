/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   jobs_list_counter.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggwin-go <ggwin-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/31 14:15:35 by ggwin-go          #+#    #+#             */
/*   Updated: 2019/08/31 14:15:36 by ggwin-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

int				jobs_list_counter(t_jobs *local_job)
{
	int			iter;

	iter = 0;
	while (local_job)
	{
		local_job = local_job->next;
		iter++;
	}
	return (iter);
}
