/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_if_clause.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwisoky <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 17:35:06 by dwisoky           #+#    #+#             */
/*   Updated: 2019/09/10 18:57:51 by dwisoky          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

/*
** Grammar rule
** if_clause        : If compound_list Then compound_list else_part Fi
**                  | If compound_list Then compound_list           Fi
**                  ;
*/

t_if_clause			*parser_free_if_clause(t_if_clause *list)
{
	if (!list)
		return (NULL);
	parser_free_compound_list(list->if_head);
	parser_free_compound_list(list->if_body);
	parser_free_else_part(list->else_part);
	free(list);
	return (NULL);
}

static t_if_clause	*parser_init_if_clause(void)
{
	t_if_clause		*list;

	list = (t_if_clause*)ft_xmemalloc(sizeof(t_if_clause));
	list->if_head = NULL;
	list->if_body = NULL;
	list->else_part = NULL;
	return (list);
}

t_if_clause			*parser_if_clause(void)
{
	t_if_clause		*list;

	g_lex = g_lex->next;
	list = parser_init_if_clause();
	list->if_head = parser_compound_list();
	if (g_error_lex)
		return (parser_free_if_clause(list));
	if (g_lex->type == WORD && ft_strequ(g_lex->lexem, "then"))
		g_lex = g_lex->next;
	else
	{
		g_error_lex = g_lex;
		return (parser_free_if_clause(list));
	}
	list->if_body = parser_compound_list();
	list->else_part = parser_else_part();
	if (g_error_lex)
		return (parser_free_if_clause(list));
	if (g_lex->type == WORD && ft_strequ(g_lex->lexem, "fi"))
	{
		g_lex = g_lex->next;
		return (list);
	}
	g_error_lex = g_lex;
	return (parser_free_if_clause(list));
}
