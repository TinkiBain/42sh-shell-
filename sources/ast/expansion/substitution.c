/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   substitution.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwisoky <dwisoky@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/03 20:58:11 by dwisoky           #+#    #+#             */
/*   Updated: 2019/10/19 21:27:59 by dwisoky          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

extern t_opt	g_opt;

char			*substitution_write(int pipefd[2], pid_t pid, char *str)
{
	char		buf[1024];
	char		*tmp;
	int			i;

	free(str);
	close(pipefd[1]);
	waitpid(pid, NULL, 0);
	tmp = ft_strnew(1);
	while ((i = read(pipefd[0], buf, 1023)))
	{
		buf[i] = '\0';
		tmp = ft_xstrrejoin(tmp, buf, 1);
	}
	close(pipefd[0]);
	if (ft_strlen(tmp))
		tmp[ft_strlen(tmp) - 1] = '\0';
	return (tmp);
}

char			*substitution_exec(char *str)
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
		close(0);
		g_opt.vi_mode = 0;
		g_opt.emacs_mode = 0;
		g_opt.rl_gnl = 1;
		parser_list = exec_ast(str, &lex);
		if (parser_list)
			traverse_ast(parser_list);
		parser_free(parser_list);
		lexer_free_all(lex);
		exit(0);
	}
	else if (pid == -1)
		print_error_exit("fork error", NULL, 1);
	return (substitution_write(pipefd, pid, str));
}

char			*substitution(char *str)
{
	char		*tmp;
	char		*begin;

	begin = str;
	tmp = str;
	if (*str == '$')
	{
		begin += 2;
		str = lexer_find_dollar(str + 1);
	}
	else
	{
		str = lexer_find_char(begin, '`');
		begin++;
	}
	begin = ft_xstrndup(begin, str - begin);
	begin = cleaner(begin);
	free(tmp);
	return (substitution_exec(begin));
}
