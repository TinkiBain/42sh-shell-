/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   jobs_list_handler.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jterry <jterry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/09 18:24:35 by jterry            #+#    #+#             */
/*   Updated: 2019/11/02 19:08:46 by jterry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

void			freedsubjob(t_job **new)
{
	free((*new)->status);
	free((*new)->name);
	(*new)->status = NULL;
	(*new)->name = NULL;
	free((*new));
	(*new) = NULL;
}

static void		freedjob(t_pjobs **new)
{
	t_job		*subnew;

	free((*new)->status);
	free((*new)->name);
	(*new)->status = NULL;
	(*new)->name = NULL;
	while ((*new)->job)
	{
		subnew = (*new)->job->next;
		freedsubjob(&(*new)->job);
		(*new)->job = subnew;
	}
	free((*new));
	(*new) = NULL;
}

void			deletejob(t_pjobs **alst, int num)
{
	t_pjobs		*prev;
	t_pjobs		*new;

	prev = (*alst);
	while (prev && prev->num != num)
	{
		if (prev == (*alst))
			new = prev;
		else
			new = new->next;
		prev = prev->next;
	}
	if ((*alst)->num == num)
	{
		prev = (*alst)->next;
		freedjob(alst);
		(*alst) = prev;
	}
	else
	{
		new->next = prev->next;
		freedjob(&prev);
	}
}

int				ft_num_job(t_pjobs *localjob)
{
	int			min;
	t_pjobs		*first;

	min = 1;
	first = localjob;
	while (localjob)
	{
		if (min == localjob->num)
		{
			localjob = first;
			min++;
		}
		else
			localjob = localjob->next;
	}
	return (min);
}

t_pjobs			*ft_addjob(char *path, int flag, int list_num)
{
	t_pjobs		*new;

	if (!(new = (t_pjobs*)malloc(sizeof(t_pjobs))))
		return (NULL);
	new->flag = flag;
	new->name = path;
	new->status = ft_xstrdup("\trunning\t\t");
	new->next = NULL;
	if (flag || list_num)
		new->num = ft_num_job(g_jobs_list);
	else
		new->num = 1;
	new->workgpid = 0;
	new->job = NULL;
	return (new);
}
