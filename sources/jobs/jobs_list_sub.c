/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   jobs_list_sub.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jterry <jterry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/01 18:37:06 by jterry            #+#    #+#             */
/*   Updated: 2019/09/21 19:05:13 by jterry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

t_job			*ft_addsubjob(char *path, int num)
{
	t_job		*new;

	if (!(new = (t_job*)malloc(sizeof(*new))))
		return (NULL);
	new->name = path;
	new->status = ft_xstrdup(" running\t\t");
	new->next = NULL;
	new->num = num;
	return (new);
}

t_pjobs			*lsubjob_changer(char *str, t_pjobs *gjobs, int num, int pid)
{
	t_job		*local;

	local = NULL;
	while (gjobs->num != num)
		gjobs = gjobs->next;
	if (!gjobs->job)
	{
		gjobs->job = ft_addsubjob(str, num);
		local = gjobs->job;
	}
	else
	{
		local = gjobs->job;
		while (local->next)
			local = local->next;
		local->next = ft_addsubjob(str, num);
		local = local->next;
	}
	local->pid = pid;
	return (gjobs);
}

t_pjobs			*ljobs_startet(char *str, int flag, int num, int pid)
{
	if (flag)
		return (lsubjob_changer(str, g_pjobs, num, pid));
	else
		return (lsubjob_changer(str, g_subjob, num, pid));
}
