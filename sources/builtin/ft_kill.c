/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_kill.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jterry <jterry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/09 17:46:30 by jterry            #+#    #+#             */
/*   Updated: 2019/09/12 18:01:54 by jterry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

static int		ft_isstrnum(const char *c)
{
	int			i;

	i = 0;
	while (c[i])
	{
		if (!(c[i] >= 48 && c[i] <= 57))
			return (0);
		i++;
	}
	return (1);
}

static void		kill_hendler_proc(const char **cmd, t_pjobs *local_job, int sig)
{
	int			num;

	num = ft_atoi(&(*cmd)[1]);
	if (num == 0)
		while (local_job && local_job->next)
			local_job = local_job->next;
	else
		while (local_job && local_job->num != num)
			local_job = local_job->next;
	if (!local_job && num)
	{
		ft_printf("kill: %%%d: no such job\n", num);
		cmd++;
		return ;
	}
	if (local_job)
		kill(local_job->job->pid, sig);
}

static void		kill_hendler(const char **cmd, t_pjobs *local_job,
		int sig, t_pjobs *fir)
{
	int			kek;

	if (**cmd == '%')
	{
		kill_hendler_proc(cmd, local_job, sig);
		local_job = fir;
	}
	else
	{
		if (ft_isstrnum(*cmd))
		{
			kek = ft_atoi((*cmd));
			if (kill(kek, sig) < 0)
				ft_printf("kill: %d: no such process\n", kek);
		}
		else
			ft_printf("kill: illegal pid: %s\n", (*cmd));
	}
}

static int	ft_sighendler(const char *str)
{
	if (!ft_strcmp(str, "SIGCONT"))
		return (SIGCONT);
	else if (!ft_strcmp(str, "SIGSTOP"))
		return (SIGSTOP);
	else if (!ft_strcmp(str, "SIGINT"))
		return (SIGINT);
	else if (!ft_strcmp(str, "SIGKILL"))
		return (SIGKILL);
	else if (!ft_strcmp(str, "SIGTTOU"))
		return (SIGTTOU);
	return (-1);
}

/*
** sig always = 15
*/

int			ft_kill(const char **cmd, t_pjobs *local_job, int sig)
{
	t_pjobs		*fir;

	fir = local_job;
	if (*cmd && (*cmd)[0] == '-' && (*cmd)[1] != '-' && (*cmd)[1] != 's')
		sig = ft_atoi(*cmd++) * -1;
	if (*cmd && (*cmd)[0] == '-' && (*cmd)[1] == 's')
	{
		cmd++;
		if ((sig = ft_sighendler(*cmd) > 0))
			cmd++;
		else
			sig = SIGSTOP;
	}
	if (!(*cmd))
	{
		ft_putstr("kill: not enough arguments");
		return (1);
	}
	while (*cmd)
	{
		kill_hendler(cmd, local_job, sig, fir);
		cmd++;
	}
	return (0);
}
