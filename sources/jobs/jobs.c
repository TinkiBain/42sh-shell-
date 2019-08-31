/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   jobs.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggwin-go <ggwin-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/30 17:04:18 by jterry            #+#    #+#             */
/*   Updated: 2019/08/31 14:10:17 by ggwin-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

static int		*order_creat(t_jobs *local, int len)
{
	int			*ord;
	int			i;
	int			tmp;

	i = 0;
	ord = (int*)malloc(sizeof(int) * len);
	while (local)
	{
		ord[i++] = local->num;
		local = local->next;
	}
	ord[i] = '\0';
	i = 0;
	while (ord[i] && ord[i + 1] != 0)
	{
		if (ord[i] > ord[i + 1])
		{
			tmp = ord[i];
			ord[i] = ord[i + 1];
			ord[i + 1] = tmp;
			i = -1;
		}
		i++;
	}
	return (ord);
}

/*
** iter always = -1
*/

void			jobs(t_jobs *local_job, int iter, char *cmd)
{
	int			*order;
	t_jobs		*first;

	first = local_job;
	order = order_creat(g_jobs, jobs_list_counter(g_jobs));
	local_job = first;
	while (order[++iter] != 0)
	{
		while (local_job)
		{
			if (local_job->num == order[iter])
			{
				if (cmd && !ft_strcmp(cmd, "-l") &&
						!ft_strcmp(local_job->status, "[Running]"))
					ft_printf("[%s]\t%s\t%s\n", local_job->str_num,
							local_job->status, local_job->name);
				else if (!cmd || (cmd && ft_strcmp(cmd, "-l")))
					ft_printf("[%s]\t%s\t%s\n", local_job->str_num,
							local_job->status, local_job->name);
				local_job = first;
				break ;
			}
			local_job = local_job->next;
		}
	}
}
