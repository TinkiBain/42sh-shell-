/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_case_item.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwisoky <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 19:36:48 by dwisoky           #+#    #+#             */
/*   Updated: 2019/09/13 21:13:45 by dwisoky          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

/*
** Grammar rule
** case_item        :     pattern ')' linebreak     DSEMI linebreak
**                  |     pattern ')' compound_list DSEMI linebreak
**                  | '(' pattern ')' linebreak     DSEMI linebreak
** 	                | '(' pattern ')' compound_list DSEMI linebreak
**                  ;
** for the last case element, you can apply
** case_item_ns     :     pattern ')'               linebreak
**                  |     pattern ')' compound_list linebreak
** 	                | '(' pattern ')'               linebreak
**	                | '(' pattern ')' compound_list linebreak
**                  ;
*/

t_case_item			*parser_free_case_item(t_case_item *list)
{
	if (!list)
		return (NULL);
	parser_free_pattern(list->pattern);
	parser_free_compound_list(list->compound_list);
	free(list);
	return (NULL);
}

static t_case_item	*parser_init_case_item(void)
{
	t_case_item		*list;

	list = (t_case_item*)ft_xmalloc(sizeof(t_case_item));
	list->pattern = NULL;
	list->compound_list = NULL;
	return (list);
}

t_case_item			*parser_case_item(void)
{
	t_case_item		*list;

	list = parser_init_case_item();
	if (g_lex->type == LBRACKET)
		g_lex = g_lex->next;
	list->pattern = parser_pattern();
	if (g_error_lex)
		return (parser_free_case_item(list));
	if (g_lex->type != RBRACKET)
	{
		g_error_lex = g_lex;
		return (parser_free_case_item(list));
	}
	g_lex = g_lex->next;
	parser_linebreak();
	list->compound_list = parser_compound_list();
	if (g_error_lex)
		return (parser_free_case_item(list));
	if (g_lex->type == DSEMI)
		g_lex = g_lex->next;
	else
		g_parser_case_list_end = 1;
	parser_linebreak();
	return (list);
}
