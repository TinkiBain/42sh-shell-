/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fc_edit_run_editor.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jterry <jterry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 20:32:41 by gmelisan          #+#    #+#             */
/*   Updated: 2019/10/24 22:25:02 by jterry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fc.h"

int			ft_fc_edit_run_editor(char **argv, t_pjobs **local)
{
	extern char		**environ;
	pid_t			pid;

	if ((pid = fork()) < 0)
	{
		loginfo("ft_fc(): fork error (%s %s)", argv[0], argv[1]);
		return (1);
	}
	if (pid == 0 && execve(argv[0], argv, environ) < 0)
	{
		loginfo("ft_fc(): execve error (%s %s)", argv[0], argv[1]);
		return (1);
	}
	(*local) = ljobs_started(ft_xstrdup("fc"),
		(*local)->flag, (*local)->num, pid);
	ft_waitpid(pid, NULL);
	return (g_res_exec);
}
