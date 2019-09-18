/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_exec_subshell.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwisoky <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 20:13:28 by dwisoky           #+#    #+#             */
/*   Updated: 2019/09/18 16:53:33 by dwisoky          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void			parser_exec_subshell(char *cmd, char **new_str)
{
	pid_t		pid;
	int			pipefd[2];
	extern char	*g_shell_path;
	extern char	**environ;
	char		str[1024];
	int			tmp;
	char		*arr[2];

	arr[0] = g_shell_path;
	arr[1] = NULL;
	if (pipe(pipefd))
		exit (-1);
	write(pipefd[1], cmd, ft_strlen(cmd));
	write(pipefd[1], "\nexit\n", 6);
	if ((pid = fork()) == 0)
	{
		dup2(pipefd[0], 0);
		dup2(pipefd[1], 1);
		close(pipefd[0]);
		close(pipefd[1]);
		execve(g_shell_path, arr, environ);
	}
	else
	{
		close(pipefd[1]);
		waitpid(pid, NULL, 0);
		while ((tmp = read(pipefd[0], str, 1023)))
		{
			str[tmp - 1] = '\0';
			*new_str = ft_strrejoin(*new_str, str, 1);
		}
		close(pipefd[0]);
	}
}

char		*parser_expansion_subshell(char *str, char **new_str)
{
	char	*tmp;
	char	*begin;
	char	stop_sim;

	if (*str == '`')
		stop_sim = '`';
	else
		stop_sim = ')';
	++str;
	begin = str;
	tmp = ft_strnew(0);
	while (*str != stop_sim)
	{
		if (!*str)
		{
			tmp = ft_strrejoin(tmp, ft_strndup(begin, str - begin), 3);
			str = parser_recall_readline(stop_sim);
			begin = str;
		}
		else if (*str == '\\')
		{
			tmp = ft_strrejoin(tmp, ft_strndup(begin, str - begin), 3);
			++str;
			begin = str;
			++str;
		}
		else
			++str;
	}
	tmp = ft_strrejoin(tmp, ft_strndup(begin, str - begin), 3);
	parser_exec_subshell(tmp, new_str);
	free(tmp);
	return (str + 1);
}
