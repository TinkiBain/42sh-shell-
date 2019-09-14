/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   traverse_compound_list.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggwin-go <ggwin-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 21:57:35 by ggwin-go          #+#    #+#             */
/*   Updated: 2019/09/14 14:05:17 by ggwin-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

void		traverse_compound_list(t_compound_list *list, char **env,
														t_pjobs *local)
{
	char	*str;
	char	*av[3];
	int		fd;
	pid_t	pid;

	av[0] = PROJECT_NAME;
	av[1] = "./test_subshell";
	av[2] = NULL;
	str = get_job_name(list->lex_begin, list->lex_end, list->separator);
	fd = open(av[1], O_RDWR | O_CREAT | O_TRUNC, 0644);
	write(fd, str, ft_strlen(str));
	if ((pid = fork()) == 0)
	{
		if (local->flag == 1)
			setpgrp();
		if (execve(g_shell_path, av, env) == -1)
			exit(-1);
	}
	else
	{
		ljobs_startet("subshell_name", local->flag, local->num, pid);
		if (local->flag == 0)
			ft_waitpid(pid);
		else
			ft_printf("[%d] [%d]\n", local->num, pid);
		set_result();
		ft_strdel(&str);
	}
}
