/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_ast.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggwin-go <ggwin-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/27 01:39:35 by gmelisan          #+#    #+#             */
/*   Updated: 2019/09/19 19:33:09 by dwisoky          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

t_complete_cmd		*exec_ast(char *buf, t_lex **lex)
{
	t_complete_cmd	*list;
	extern char		*g_buf;

	*lex = lexer(buf);
	if (!*lex)
	{
		free(buf);
		return (NULL);
	}
	g_buf = buf;
	while ((*lex)->back)
		(*lex) = (*lex)->back;
	g_lex = *lex;
	g_error_lex = NULL;
	list = parser();
	if (g_error_lex)
	{
		parser_print_error();
		if (g_error_lex->type == EOF)
			free(g_error_lex);
		list = parser_free(list);
	}
	free(g_buf);
	return (list);
}
