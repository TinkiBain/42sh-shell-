/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fc_edit_run_editor.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jterry <jterry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 20:32:41 by gmelisan          #+#    #+#             */
/*   Updated: 2019/10/23 19:40:07 by jterry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fc.h"

int			ft_fc_edit_run_editor(char **argv)
{
	extern char		**environ;
	pid_t			pid;

	pid = fork();
	if (pid == 0 && execve(argv[0], argv, environ) < 0)
	{
		loginfo("ft_fc(): execve error (%s %s)", argv[0], argv[1]);
		return (1);
	}
	else if (pid > 0)
		ft_waitpid(pid, NULL);
	else
	{
		loginfo("ft_fc(): fork error (%s %s)", argv[0], argv[1]);
		return (1);
	}
	return (g_res_exec);
}
