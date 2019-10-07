/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_function_definition.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwisoky <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 16:19:16 by dwisoky           #+#    #+#             */
/*   Updated: 2019/10/05 20:39:18 by dwisoky          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

/*
** Grammar rule
** function_definition : fname '(' ')' linebreak function_body
**                     ;
*/

t_func_definition	*parser_free_function_definition(t_func_definition *list)
{
	if (!list)
		return (NULL);
	if (list->function_name)
		free(list->function_name);
	parser_free_function_body(list->function_body);
	free(list);
	return (NULL);
}

t_func_definition	*parser_init_function_definition(void)
{
	t_func_definition	*list;

	list = (t_func_definition*)ft_xmalloc(sizeof(t_func_definition));
	list->function_name = NULL;
	list->function_body = NULL;
	return (list);
}

t_func_definition	*parser_function_definition(void)
{
	t_func_definition	*list;

	list = parser_init_function_definition();
	list->function_name = parser_fname();
	if (g_error_lex)
		return (parser_free_function_definition(list));
	g_lex = g_lex->next->next;
	if (g_lex->type != RBRACKET)
	{
		g_error_lex = g_lex;
		return (parser_free_function_definition(list));
	}
	g_lex = g_lex->next;
	parser_linebreak();
	list->function_body = parser_function_body();
	return (list);
}
