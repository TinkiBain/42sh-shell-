/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_ast.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggwin-go <ggwin-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/27 01:39:35 by gmelisan          #+#    #+#             */
/*   Updated: 2019/09/10 16:48:43 by dwisoky          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

t_complete_cmd		*exec_ast(char *buf, t_lex **lex)
{
	t_complete_cmd	*list;

	*lex = lexer(buf);
	if (!*lex)
	{
		free(buf);
		return (NULL);
	}
	while ((*lex)->back)
		(*lex) = (*lex)->back;
	g_lex = *lex;
	g_error_lex = NULL;
	list = parser();
	if (g_error_lex)
	{
		parser_print_error();
		list = parser_free(list);
	}
	free(buf);
	return (list);
}
