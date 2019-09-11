/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   traverse_compound_command.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggwin-go <ggwin-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 19:24:51 by ggwin-go          #+#    #+#             */
/*   Updated: 2019/09/11 18:53:17 by ggwin-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

static char	*get_input_str(t_lex *lex, t_lex *lex_end, int separator)
{
	char	*str;
	char	*tmp;

	(lex->lexem) ? str = ft_xstrdup(lex->lexem) : ft_itoa(lex->type);
	while ((lex = lex->next) && lex < lex_end)
	{
		tmp = ft_strjoin(" ", (lex->lexem) ? lex->lexem : ft_itoa(lex->type));
		str = ft_strrejoin(str, tmp, 3);
	}
	if (separator == JOB)
	{
		tmp = ft_strjoin(" ", ft_itoa(separator));
		str = ft_strrejoin(str, tmp, 3);
	}
	return (str);
}

static void	call_subshell(t_compound_list *list, char **env)
{
	char	*subshell_str;
	char	*av[3];
	int		fd;
	pid_t	pid;

	av[0] = PROJECT_NAME;
	av[1] = "./test_subshell";
	av[2] = NULL;
	subshell_str = get_input_str(list->lex_begin, list->lex_end, list->separator);
	fd = open(av[1], O_RDWR | O_CREAT | O_TRUNC, 0644);
	write(fd, subshell_str, ft_strlen(subshell_str));
	if ((pid = fork()) == 0)
	{
		if (execve(g_shell_path, av, env) == -1)
			exit(-1);
	}
	waitpid(pid, &g_res_exec, 0);
	free(subshell_str);
}

static int	if_subhell(t_if_clause *list, char **env)
{
	call_subshell(list->if_head, env);
	if (!g_res_exec)
	{
		printf("res = 0\n");
		call_subshell(list->if_body, env);
	}
	// else if (1)
	// {

	// }
	return (0);
}

void		traverse_compound_command(t_compound_cmd *cmd, char **env, int in_fork)
{
	if (cmd->if_clause)
		if_subhell(cmd->if_clause, env);
	else
		call_subshell(cmd->compound_list, env);
		// cmd->if_clause
	(void)in_fork;
}
