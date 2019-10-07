/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   substitution.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwisoky <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/03 20:58:11 by dwisoky           #+#    #+#             */
/*   Updated: 2019/10/07 22:30:27 by dwisoky          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

char		*substitution_write(int pipefd[2])
{
	char	buf[1024];
	char	*tmp;
	int		i;

	tmp = ft_strnew(1);
	while ((i = read(pipefd[0], buf, 1023)))
	{
		buf[i] = '\0';
		tmp = ft_strrejoin(tmp, buf, 1);
	}
	close(pipefd[0]);
	tmp[ft_strlen(tmp) - 1] = '\0';
	return (tmp);
}

char		*substitution_exec(char *str)
{
	pid_t			pid;
	t_complete_cmd	*parser_list;
	int				pipefd[2];
	t_lex			*lex;

	if (pipe(pipefd) < 0)
		exit(-1);
	if (!(pid = fork()))
	{
		close(pipefd[0]);
		dup2(pipefd[1], 1);
		lex = NULL;
		parser_list = exec_ast(str, &lex);
		if (parser_list)
			traverse_ast(parser_list);
		parser_free(parser_list);
		lexer_free_all(lex);
		exit(0);
	}
	close(pipefd[1]);
	waitpid(pid, NULL, 0);
	return (substitution_write(pipefd));
}

char		*substitution(char *str)
{
	char	*begin;

	begin = str;
	if (*str == '$')
	{
		begin += 2;
		str = lexer_find_dollar(str);
	}
	else
	{
		begin++;
		str = lexer_find_char(begin, '`');
	}
	begin = ft_strndup(begin, str - begin);
	return (substitution_exec(begin));
}
