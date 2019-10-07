/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   substitution.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jterry <jterry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/03 20:58:11 by dwisoky           #+#    #+#             */
/*   Updated: 2019/10/07 21:50:50 by jterry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

char		*substitution_write(int pipefd[2], int tmpfd)
{
	char	buf[1024];
	char	*tmp;
	int		i;

	tmp = ft_strnew(1);
	close(pipefd[1]);
	while ((i = read(pipefd[0], buf, 1023)))
	{
		buf[i] = '\0';
		tmp = ft_strrejoin(tmp, buf, 1);
	}
	close(pipefd[0]);
	dup2(tmpfd, 1);
	tmp[ft_strlen(tmp) - 1] = '\0';
	return (tmp);
}

char		*substitution_exec(char *str)
{
	extern char		*g_buf;
	t_complete_cmd	*parser_list;
	int				pipefd[2];
	int				tmpfd;
	t_lex			*lex;
	t_lex			*tmp;
	char			*src;

	if (pipe(pipefd) < 0)
		return (NULL);
	tmpfd = dup(1);
	dup2(pipefd[1], 1);
	lex = NULL;
	tmp = g_lex;
	src = g_buf;
	parser_list = exec_ast(str, &lex);
	if (parser_list)
		traverse_ast(parser_list);
	parser_free(parser_list);
	lexer_free_all(lex);
	g_lex = tmp;
	g_buf = src;
	return (substitution_write(pipefd, tmpfd));
}

char		*substitution(char *str)
{
	char	*begin;

	begin = str;
	if (*str == '$')
	{
		begin += 2;
		str = parser_find_dollar(str);
	}
	else
	{
		begin++;
		str = lexer_find_char(begin, '`');
	}
	begin = ft_strndup(begin, str - begin);
	return (substitution_exec(begin));
}
