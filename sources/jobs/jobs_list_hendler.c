/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cjobs_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jterry <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/09 18:24:35 by jterry            #+#    #+#             */
/*   Updated: 2019/08/26 16:06:02 by jterry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void		freedjob(t_jobs **new)
{
	(*new)->status = NULL;
	free((*new)->status);
	(*new)->str_num = NULL;
	free((*new)->str_num);
	(*new)->name = NULL;
	free((*new)->name);
	free((*new));
	(*new) = NULL;
}

void			deletejob(t_jobs **alst, int num)
{
	t_jobs		*prew;
	t_jobs		*new;

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

static char		*only_name(char *path)
{
	char		*tmp;
	int			i;

	i = 0;
	i = ft_strlen(path);
	while (path[i] != '/')
		i--;
	tmp = ft_strdup(&path[i + 1]);
	return (tmp);
}

static int		ft_num_job(t_jobs *localjob)
{
	int			min;
	t_jobs		*first;

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

t_jobs			*ft_addjob(char *path)
{
	t_jobs		*new;

	new = (t_jobs*)malloc(sizeof(t_jobs));
	new->name = only_name(path);
	new->status = ft_strdup("[Running]");
	new->next = NULL;
	new->num = ft_num_job(joba);
	new->str_num = ft_itoa(new->num);
	return (new);
}
