/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_ast.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelisan <gmelisan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/27 01:39:35 by gmelisan          #+#    #+#             */
/*   Updated: 2019/08/29 19:15:00 by dwisoky          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

/*
** variable for launch shell with param
** (now using for print ast instead for exec cmd).
*/

/*
** global variable for internal shell variables.
*/

char				**g_var;
char				**g_var_names;
t_opt				g_opt;

static char			*fill_dquote(char *str)
{
	while (*str)
	{
		if (*str == '\\')
		{
			++str;
			if (*str)
				++str;
			else
				g_error_pars = 2;
		}
		else if (*str == '"')
			return (str + 1);
		else
			++str;
	}
	g_error_pars = 2;
	return (str);
}

static char			*fill_quote(char *str)
{
	while (*str)
	{
		if (*str == '\'')
			return (str + 1);
		++str;
	}
	g_error_pars = 2;
	return (str);
}

static void			check_quotes(char *str)
{
	while (*str)
	{
		if (*str == '"')
			str = fill_dquote(str + 1);
		else if (*str == '\'')
			str = fill_quote(str + 1);
		else if (*str == '\\')
		{
			++str;
			if (*str)
				++str;
			else
				g_error_pars = 2;
		}
		else
			++str;
	}
}

static t_pars_list	*ast_treatment_error(char *buf)
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

t_pars_list			*exec_ast(char *buf)
{
	t_lex		*lex;
	t_lex		*src;
	t_pars_list	*list;

	lex = NULL;
	lex = lexer(buf);
	if (!lex)
	{
		free(buf);
		return (NULL);
	}
	src = lex;
	while (src->next)
		src = src->next;
	list = parser(NULL);
	check_quotes(buf);
	lexer_free_all(src);
	if (g_error_pars == 1)
		return (parser_free_list(list));
	if (g_error_pars == 2)
	{
		parser_free_list(list);
		return (ast_treatment_error(buf));
	}
	free(buf);
	return (list);
}
