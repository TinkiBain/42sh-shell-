/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   jobs.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jterry <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/30 17:04:18 by jterry            #+#    #+#             */
/*   Updated: 2019/08/25 20:15:50 by jterry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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

static int		list_counter(t_jobs *local_job)
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

/*
** iter always = -1
*/

void			jobs(t_jobs *local_job, int iter, char *cmd)
{
	int			*order;
	t_jobs		*first;

	first = local_job;
	order = order_creat(joba, list_counter(joba));
	local_job = first;
	while (order[++iter] != 0)
	{
		while (local_job)
		{
			if (local_job->num == order[iter])
			{
				if (cmd && !ft_strcmp(cmd, "-l") &&
						!ft_strcmp(local_job->status, "[Running]"))
					printf("[%s]\t%s\t%s\n", local_job->str_num,
							local_job->status, local_job->name); //!!
				else if (!cmd || (cmd && ft_strcmp(cmd, "-l")))
					printf("[%s]\t%s\t%s\n", local_job->str_num,
							local_job->status, local_job->name); //!!
				local_job = first;
				break ;
			}
			local_job = local_job->next;
		}
	}
}

static t_jobs		*last_elem(t_jobs *job)
{
	int			i;
	int			len;

	i = 0;
	len = list_counter(job);
	while (i < len - 1)
	{
		i++;
		job = job->next;
	}
	return (job);
}

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
		local_job = last_elem(local_job);
	if (local_job == NULL)
	{
		ft_putstr("Not such job");
		return ;
	}
	tcsetpgrp(0, local_job->PID);
	kill(local_job->PID, SIGCONT);
	free(local_job->status);
	local_job->status = ft_strdup("[Running]");
	waitpid(local_job->PID, &st, 0);
}

void			bg(t_jobs *local_job, char *name)
{
	if (name && name[1])
		while (local_job)
		{
			if (!ft_strcmp(local_job->name, name)
					|| !ft_strcmp(local_job->str_num, &name[1]))
				break ;
			local_job = local_job->next;
		}
	else
		local_job = last_elem(local_job);
	if (local_job == NULL)
	{
		ft_putstr("Not such job");
		return ;
	}
	setpgid(local_job->PID, 0);
	kill(local_job->PID, SIGCONT);
	free(local_job->status);
	local_job->status = ft_strdup("[Running]");
	printf("[%d]\t[Continued]\t%s\n", local_job->num, local_job->name); //!!
}
