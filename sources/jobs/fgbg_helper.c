/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fgbg_helper.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jterry <jterry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/01 18:50:01 by jterry            #+#    #+#             */
/*   Updated: 2019/09/01 19:48:13 by jterry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

static int				find_highnum(t_pjobs *local)
{
	int highnum;

	highnum = 0;
	while (local)
		{
			if (local->num > highnum)
				highnum = local->num;
			local = local->next;
		}
	return (highnum);
}

static t_pjobs			*find_job(t_pjobs *local, int flag)
{
	int			high;

	if (flag == 0)
		high = find_highnum(local);
	else
		high = flag;
	while (local && local->num != high)
		local = local->next;
	return (local);
}

static int				spec_strlen(char *str)
{
	int			i;

	i = 0;
	while (str[i] && str[i] != ' ' && str[i] != '|')
		i++;
	return (i);
}

t_pjobs			*name_proc_hendl(t_pjobs *local_job, char *name)
{
	int			high;
	t_pjobs		*local;
	int			i;

	i = 0;
	local = local_job;
	high = find_highnum(local_job);
	local_job = find_job(local_job, 0);
	if (name && name[0] != '%')
		while (!ft_strncmp(local_job->name, name, spec_strlen(name)))
		{
			local_job = find_job(local, high - i);
			i++;
		}
	else if (name && name[0] == '%' && name[1])
		local_job = find_job(local, ft_atoi(&name[1]));
	else
		local_job = jobs_last_elem(local_job);
	return (local_job);
}
