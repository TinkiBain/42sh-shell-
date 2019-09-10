/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_else_part.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwisoky <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 18:47:42 by dwisoky           #+#    #+#             */
/*   Updated: 2019/09/10 19:30:27 by dwisoky          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

/*
** Grammar rule
** else_part        : Elif compound_list Then else_part
**                  | Else compound_list
**                  ;
*/

t_else_part			*parser_free_else_part(t_else_part *list)
{
	if (!list)
		return (NULL);
	parser_free_compound_list(list->compound_list);
	parser_free_else_part(list->next_else_part);
	free(list);
	return (NULL);
}

static t_else_part	*parser_init_else_part(void)
{
	t_else_part		*list;

	list = (t_else_part*)ft_xmalloc(sizeof(t_else_part));
	list->compound_list = NULL;
	list->next_else_part = NULL;
	return (list);
}

t_else_part			*parser_else_part(void)
{
	t_else_part		*list;

	if (g_error_lex)
		return (NULL);
	list = parser_init_else_part();
	if (g_lex->type == WORD && ft_strequ(g_lex->lexem, "else"))
		list->elif = 0;
	else if (g_lex->type == WORD && ft_strequ(g_lex->lexem, "elif"))
		list->elif = 1;
	else
		g_error_lex = g_lex;
	if (g_error_lex)
		return (parser_free_else_part(list));
	g_lex = g_lex->next;
	list->compound_list = parser_compound_list();
	if (!list->elif)
		return (list);
	if (g_lex->type == WORD && ft_strequ(g_lex->lexem, "then"))
		g_lex = g_lex->next;
	else
		g_error_lex = g_lex;
	list->next_else_part = parser_else_part();
	if (g_error_lex)
		return (parser_free_else_part(list));
	return (list);
}
