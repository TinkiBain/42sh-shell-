/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   jobs_list_sub.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jterry <jterry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/01 18:37:06 by jterry            #+#    #+#             */
/*   Updated: 2019/09/14 13:25:16 by jterry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

t_job			*ft_addsubjob(char *path, int num)
{
	t_job		*new;

	new = (t_job*)malloc(sizeof(*new));
	new->name = path;
	new->status = ft_strdup("\t[Running]\t");
	new->next = NULL;
	new->num = num;
	return (new);
}

t_job			*lsubjob_changer(char *str, t_pjobs *gjobs, int num, int pid)
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
	local = local->next;
	return (local);
}

t_job			*ljobs_startet(char *str, int flag, int num, int pid)
{
	if (flag)
		return (lsubjob_changer(str, g_pjobs, num, pid));
	else
		return (lsubjob_changer(str, g_subjob, num, pid));
}
