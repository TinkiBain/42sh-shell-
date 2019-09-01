/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggwin-go <ggwin-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/01 20:45:11 by ggwin-go          #+#    #+#             */
/*   Updated: 2019/09/01 16:03:36 by dwisoky          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"
#include "parser.h"
#include "exec.h"

/*
 **	variable for launch shell with param
 **(now using for print ast instead for exec cmd).
*/

/*
 **	global variable for internal shell variables.
*/

char		**g_var;
char		**g_var_names;

t_pars_list	*ast_treatment_error(char *buf)
{
	char	*tmp;

	buf = ft_strrejoin(buf, "\n", 1);
	tmp = buf;
	buf = ft_readline("> ", tmp);
	free(tmp);
	ft_putstr("\n");
	g_error_pars = 0;
	return (exec_ast(buf));
}

t_pars_list	*exec_ast(char *buf)
{
	t_lex		*lex;
	t_lex		*src;
	t_pars_list	*list;

	lex = lexer(buf);
	src = lex;
	while (src->next)
		src = src->next;
	list = parser(lex, NULL, 0);
	check_quotes(buf);
	lexer_free_all(src);
	if (g_error_pars == 1)
		return (parser_free_tree(list));
	if (g_error_pars == 2)
	{
		parser_free_tree(list);
		return (ast_treatment_error(buf));
	}
	free(buf);
	return (list);
}

int			main(int ac, char **av)
{
	char		*buf;
	char		*tmp;

	init();
	if (ac > 1)
		if (ft_strequ(*(av + 1), "-v"))
			g_rl_options.vi_mode = 1;
	while (1)
	{
		buf = ft_readline("\033[0;31m" PROJECT_NAME ">\033[0m ", NULL);
		if (g_errno)
			printerr();
		if (!buf)
			break ;
		else
		{
			ft_putstr("\n");
			if (*(tmp = ft_strtrim(buf)))
				lllestb_string(buf);
			else
				free(buf);
			free(tmp);
		}
	}
	end_work();
	return (g_res_exec);
}
