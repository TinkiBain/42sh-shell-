/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggwin-go <ggwin-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/01 20:45:11 by ggwin-go          #+#    #+#             */
/*   Updated: 2019/08/13 17:14:24 by ggwin-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"
#include "parser.h"
#include "exec.h"
// #include "get_env.h"
// #include "hash.h"

/*
**	variable for launch shell with param
	(now using for print ast instead for exec cmd).
*/

int			TYPE_OF_PROGRAM;

/*
**	global variable for internal shell environment.
*/

char		**g_shell_env;

void		free_lex(t_lex *lex)
{
	if (!lex)
		return ;
	if (lex->lexeme)
		free(lex->lexeme);
	free(lex);
}

void	init_readline(void)
{
	g_history = ft_xmemalloc(sizeof(*g_history));
	history_load(g_history, DEFAULT_HIST_PATH);
}

int			main(int ac, char **av)
{
	char		*buf;
	t_pars_list	*list;
	t_lex		*lex;
	t_lex		*src;
	char		*tmp;
	extern char	**environ;

	environ = create_copy_env(environ);
	g_shell_env = environ;
	logopen();
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
				lex = lexer(buf);
				src = lex;
				while (src->next)
					src = src->next;
				list = parser(lex, NULL, 0);
				if (!g_error_pars)
				{
					if (TYPE_OF_PROGRAM)
					{
						ft_putendl("print AST:");
						print_ast(list);
						ft_putstr("\n");
					}
					else
						traverse_ast(list);
				}
				g_error_pars = 0;
				parser_free_tree(list);
				while (src->prev)
				{
					lex = src;
					src = src->prev;
					free_lex(lex);
				}
				free_lex(src);
				free(tmp);
			}
		}
		ft_strdel(&buf);
	}
	del_hash();
	history_clear(g_history);
	logclose();
	ft_free_double_ptr_arr((void ***)&environ);
	return (g_res_exec);
}
