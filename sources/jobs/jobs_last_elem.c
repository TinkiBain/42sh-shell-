/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   jobs_last_elem.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jterry <jterry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/31 14:15:44 by ggwin-go          #+#    #+#             */
/*   Updated: 2019/09/01 17:04:01 by jterry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

t_pjobs			*jobs_last_elem(t_pjobs *job)
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
