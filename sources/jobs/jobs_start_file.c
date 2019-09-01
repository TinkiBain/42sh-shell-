/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   jobs_start_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jterry <jterry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/31 17:23:02 by jterry            #+#    #+#             */
/*   Updated: 2019/08/31 20:55:05 by jterry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_jobs			*subjob_changer(char *str, t_jobs **joba, int flag)
{
	t_jobs		*local;

	local = NULL;
	if (!(*joba))
	{
		(*joba) = ft_addjob(str, flag ? 1 : 0);
		local = (*joba);
	}
	else
	{
		local = (*joba);
		while (local->next)
			local = local->next;
		local->next = ft_addjob(str, flag ? 1 : 0);
		local = local->next;
	}
	return (local);
}

t_jobs			*jobs_startet(char *str, char **argv)
{
	int i;
	int flag;

	flag = 0;
	i = 0;
	while (argv[i])
	{
		if (argv[i][0] == '&')
		{
			flag = 1;
			argv[i] = NULL;
		}
		i++;
	}
	if (flag)
		return (subjob_changer(str, &joba, flag));
	else
		return (subjob_changer(str, &subjob, flag));
}
