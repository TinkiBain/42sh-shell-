/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   jobs.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jterry <jterry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/30 17:04:18 by jterry            #+#    #+#             */
/*   Updated: 2019/09/08 20:50:08 by jterry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

static int		*order_creat(t_pjobs *local, int len)
{
	int			*ord;
	int			i;
	int			tmp;

	i = 0;
	ord = (int*)malloc(sizeof(int) * (len + 1));
	while (local)
	{
		ord[i++] = local->num;
		local = local->next;
	}
	ord[i] = 0;
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

	job = local->job;
	ft_printf("[%d]\t", local->num);
	if (job->next)
		while (job)
		{
			ft_printf("%d %s %s\n", job->pid, job->status, job->name);
			job = job->next;
		}
	else
	{
		ft_printf("%d %s %s\n", job->pid, local->status, local->name);
	}

}

int				jobs(t_pjobs *local_job, int iter, const char *cmd)
{
	int			*order;
	t_pjobs		*first;

	if (local_job)
	{
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
		free (order);
	}
	return (0);
}
