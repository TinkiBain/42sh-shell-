/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   jobs_last_elem.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggwin-go <ggwin-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/31 14:15:44 by ggwin-go          #+#    #+#             */
/*   Updated: 2019/08/31 14:15:46 by ggwin-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

t_jobs			*jobs_last_elem(t_jobs *job)
{
	int			i;
	int			len;

	i = 0;
	len = jobs_list_counter(job);
	while (i < len - 1)
	{
		i++;
		job = job->next;
	}
	return (job);
}
