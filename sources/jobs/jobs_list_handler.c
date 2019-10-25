/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   jobs_list_handler.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jterry <jterry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/09 18:24:35 by jterry            #+#    #+#             */
/*   Updated: 2019/10/25 23:16:46 by jterry           ###   ########.fr       */
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
	t_pjobs		*prew;
	t_pjobs		*new;

	prew = (*alst);
	while (prew && prew->num != num)
	{
		if (prew == (*alst))
			new = prew;
		else
			new = new->next;
		prew = prew->next;
	}
	if ((*alst)->num == num)
	{
		prew = (*alst)->next;
		freedjob(alst);
		(*alst) = prew;
	}
	else
	{
		new->next = prew->next;
		freedjob(&prew);
	}
}

static int		ft_num_job(t_pjobs *localjob)
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

t_pjobs			*ft_addjob(char *path, int flag)
{
	t_pjobs		*new;

	if (!(new = (t_pjobs*)malloc(sizeof(t_pjobs))))
		return (NULL);
	new->flag = flag;
	new->name = path;
	new->status = ft_xstrdup(" running\t");
	new->next = NULL;
	new->num = ft_num_job(g_pjobs);
	new->workgpid = 0;
	new->job = NULL;
	return (new);
}
