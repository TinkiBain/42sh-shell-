/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   jobs.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jterry <jterry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/30 17:04:18 by jterry            #+#    #+#             */
/*   Updated: 2019/09/01 19:18:20 by jterry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

static int		*order_creat(t_pjobs *local, int len)
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

void			option_print(t_pjobs *local)
{
	t_job *job;
	ft_printf("[%d]\t", local->num);
	job = local->job;
	while (job)
	{
		ft_printf("%d %s\t%s\n", job->pid, job->status, job->name);
		job = job->next;
	}
}

void			jobs(t_pjobs *local_job, int iter, char *cmd)
{
	int			*order;
	t_pjobs		*first;

	first = local_job;
	order = order_creat(g_pjobs, jobs_list_counter(g_pjobs));
	while (order[++iter] != 0)
	{
		while (local_job)
		{
			if (local_job->num == order[iter])
			{
				if (cmd && !ft_strcmp(cmd, "-l"))
					option_print(local_job);
				else if (!cmd || (cmd && ft_strcmp(cmd, "-l")))
					ft_printf("[%d]\t%s\t%s\n", local_job->num, local_job->status, local_job->name);
				local_job = first;
				break ;
			}
			local_job = local_job->next;
		}
	}
}
