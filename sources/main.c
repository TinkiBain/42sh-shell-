/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggwin-go <ggwin-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/01 20:45:11 by ggwin-go          #+#    #+#             */
/*   Updated: 2019/08/06 19:50:11 by ggwin-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"
#include "parser.h"
#include "exec.h"
// #include "get_env.h"
// #include "hash.h"

int			TYPE_OF_PROGRAM;


void	init_readline(void)
{
	g_history = ft_xmemalloc(sizeof(*g_history));
	history_load(g_history, DEFAULT_HIST_PATH);
}

t_pars_list		*exec_ast(char *buf)
{
	t_lex		*lex;
	t_lex		*src;
	t_pars_list	*list;
	char		*tmp; //убрать полсе добавления второго парметра в readline

	tmp = NULL;
	lex = lexer(buf);
	src = lex;
	while (src->next)
		src = src->next;
	list = parser(lex, NULL, 0);
	lexer_free_all(src);
	if (g_error_pars == 1)
		return (NULL);
	if (g_error_pars == 2)
	{
		tmp = ft_readline(">", tmp);// buf = ft_readline(">", tmp);
		buf = ft_strjoin(buf, tmp); // убрать после добавления второго парметра в readline
		free(tmp); // утечка на строчку выше, пропадет после добавления параметра, удалить эту строку
		g_error_pars = 0;
		return (exec_ast(buf));
	}
	return (list);
}

int			main(int ac, char **av)
{
	char		*buf;
	t_pars_list	*list;
//	t_lex		*lex;
//	t_lex		*src;
	char		*tmp;

	extern char **environ;

	init_readline();
	fill_hash_table();
	if (ac > 1)
	{
		if (ft_strequ(*(av + 1), "-p"))
			TYPE_OF_PROGRAM = 1;
		else if (ft_strequ(*(av + 1), "-v"))
			g_options.vi_mode = 1;
	}
	while (1)
	{
		buf = ft_readline("\033[0;31m" PROJECT_NAME ">\033[0m ", NULL);
		if (!buf)
			break ;
		if (g_errno)
			printerr();
		else
		{
			if (*(tmp = ft_strtrim(buf)))
			{
//				lex = lexer(buf);
//				src = lex;
//				while (src->next)
//					src = src->next;
//				list = parser(lex, NULL, 0);
				list = exec_ast(buf);
				if (TYPE_OF_PROGRAM)
				{
					ft_putendl("print AST:");
					print_ast(list);
					ft_putstr("\n");
				}
				else
					traverse_ast(list);
				g_error_pars = 0;
				parser_free_tree(list);
//				while (src->prev)
//				{
//					lex = src;
//					src = src->prev;
//					free_lex(lex);
//				}
//				free_lex(src);
//				free(tmp);
			}
		}
		ft_strdel(&buf);
	}
	del_hash();
	history_clear(g_history);
	return (g_res_exec);
}
