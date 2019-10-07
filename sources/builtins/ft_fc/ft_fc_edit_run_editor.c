/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fc_edit_run_editor.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelisan <gmelisan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 20:32:41 by gmelisan          #+#    #+#             */
/*   Updated: 2019/10/07 21:35:38 by gmelisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fc.h"

int			ft_fc_edit_run_editor(char **argv)
{
	pid_t			pid;
	extern char		**environ;
	t_pjobs			*local;
	t_string		name;

	name = str_xcopy(argv[0]);
	str_xaddback(&name, " ", 1);
	str_xaddback(&name, argv[1], ft_strlen(argv[1]));
	local = jobs_startet(name.s, JOB);
	pid = fork();
	local = ljobs_startet(ft_xstrdup(name.s), local->flag, local->num, pid);
	if (pid == 0 && execve(argv[0], argv, environ) < 0)
	{
		setpgrp();
		loginfo("ft_fc(): execve error (%s)", name.s);
		return (1);
	}
	else if (pid > 0)
		ft_waitpid(pid);
	else
	{
		loginfo("ft_fc(): fork error (%s)", name.s);
		return (1);
	}
	return (g_res_exec);
}
