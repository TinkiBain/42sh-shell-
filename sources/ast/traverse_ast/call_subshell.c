/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   call_subshell.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggwin-go <ggwin-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 14:06:19 by ggwin-go          #+#    #+#             */
/*   Updated: 2019/09/23 20:31:41 by ggwin-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

// static void		handle_child_process(int pipefd[2], t_pjobs *local)
// {
// 	extern char	**environ;
// 	char		*av[2];

// 	av[0] = PROJECT_NAME;
// 	av[1] = NULL;
// 	dup2(pipefd[0], 0);
// 	close(pipefd[0]);
// 	close(pipefd[1]);
// 	if (local->flag == 1)
// 		setpgrp();
// 	if (execve(g_shell_path, av, environ) == -1)
// 		exit(-1);
// }

void			call_subshell(char *str, t_pjobs *local)
{
	execute_line(str);
	(void)local;
	// pid_t		pid;
	// int			pipefd[2];

	// if (pipe(pipefd) == -1)
	// 	exit(-1);
	// write(pipefd[1], str, ft_strlen(str));
	// // ft_printf("%s\n", str);
	// if ((pid = fork()) == 0)
	// 	handle_child_process(pipefd, local);
	// close(pipefd[1]);
	// close(pipefd[0]);
	// local = ljobs_startet(str, local->flag, local->num, pid);
	// if (local->flag == 0)
	// 	ft_waitpid(pid);
	// else
	// 	ft_printf("[%d] [%d]\n", local->num, pid);
	// set_result();
}
