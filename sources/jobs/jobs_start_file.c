/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   jobs_start_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jterry <jterry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/31 17:23:02 by jterry            #+#    #+#             */
/*   Updated: 2019/11/02 19:09:38 by jterry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

t_pjobs			*subjob_changer(char *str, t_pjobs **gjobs, int flag, int list_num)
{
	t_pjobs		*local;

	local = NULL;
	if (!(*gjobs))
	{
		(*gjobs) = ft_addjob(str, flag ? 1 : 0, list_num);
		local = (*gjobs);
	}
	else
	{
		local = (*gjobs);
		while (local->next)
			local = local->next;
		local->next = ft_addjob(str, flag ? 1 : 0, list_num);
		local = local->next;
	}
	return (local);
}

t_pjobs			*jobs_started(char *str, int sep)
{
	int flag;

	flag = 0;
	if (sep == JOB)
		flag = 1;
	if (flag)
		return (subjob_changer(str, &g_jobs_list, flag, 1));
	else
		return (subjob_changer(str, &g_cur_job, flag, 0));
}
