/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fc_edit_run_editor.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jterry <jterry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 20:32:41 by gmelisan          #+#    #+#             */
/*   Updated: 2019/10/11 15:06:47 by jterry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fc.h"

int			ft_fc_edit_run_editor(char **argv)
{
	extern char		**environ;
	t_string		name;
	pid_t			pid;

	name = str_xcopy(argv[0]);
	str_xaddback(&name, " ", 1);
	str_xaddback(&name, argv[1], ft_strlen(argv[1]));
	pid = fork();
	if (pid == 0 && execve(argv[0], argv, environ) < 0)
	{
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
