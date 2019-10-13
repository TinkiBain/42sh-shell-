/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   jobs_list_counter.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jterry <jterry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/31 14:15:35 by jterry            #+#    #+#             */
/*   Updated: 2019/10/13 12:28:53 by jterry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

int				jobs_list_counter(t_pjobs *local_job)
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
