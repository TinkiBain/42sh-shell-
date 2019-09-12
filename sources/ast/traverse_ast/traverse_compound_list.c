/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   traverse_compound_list.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jterry <jterry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 21:57:35 by ggwin-go          #+#    #+#             */
/*   Updated: 2019/09/12 17:38:45 by jterry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

static char	*get_input_str(t_lex *lex, t_lex *lex_end, int separator)
{
	char	*str;
	char	*tmp;

	str = (lex->lexem) ? ft_xstrdup(lex->lexem) : ft_itoa(lex->type);
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

void		traverse_compound_list(t_compound_list *list, char **env)
{
	char	*str;
	char	*av[3];
	int		fd;
	pid_t	pid;

	av[0] = PROJECT_NAME;
	av[1] = "./test_subshell";
	av[2] = NULL;
	str = get_input_str(list->lex_begin, list->lex_end, list->separator);
	fd = open(av[1], O_RDWR | O_CREAT | O_TRUNC, 0644);
	write(fd, str, ft_strlen(str));
	if ((pid = fork()) == 0)
	{
		if (execve(g_shell_path, av, env) == -1)
			exit(-1);
	}
	ft_waitpid(pid);
	ft_strdel(&str);
}
