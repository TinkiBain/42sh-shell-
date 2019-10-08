/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_for_clause.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggwin-go <ggwin-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 21:35:52 by dwisoky           #+#    #+#             */
/*   Updated: 2019/10/08 17:49:12 by ggwin-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

/*
** Grammar rule
** for_clause       : For name linebreak                            do_group
**                  | For name linebreak in          sequential_sep do_group
**                  | For name linebreak in wordlist sequential_sep do_group
**                  ;
*/

t_for_clause		*parser_free_for_clause(t_for_clause *list)
{
	if (!list)
		return (NULL);
	if (list->name)
		free(list->name);
	parser_free_wordlist(list->wordlist);
	parser_free_compound_list(list->do_group);
	free(list);
	return (NULL);
}

static t_for_clause	*parser_init_for_clause(void)
{
	t_for_clause	*list;

	list = (t_for_clause*)ft_xmalloc(sizeof(t_for_clause));
	list->name = NULL;
	list->wordlist = NULL;
	list->do_group = NULL;
	return (list);
}

t_for_clause		*parser_for_clause(void)
{
	t_for_clause	*list;

	g_lex = g_lex->next;
	if (g_lex->type != WORD)
	{
		g_error_lex = g_lex;
		return (NULL);
	}
	list = parser_init_for_clause();
	list->name = parser_fname();
	if (g_error_lex)
		return (parser_free_for_clause(list));
	parser_linebreak();
	list->wordlist = parser_wordlist();
	if (g_error_lex)
		return (parser_free_for_clause(list));
	parser_sequential_sep();
	list->do_group = parser_do_group();
	if (g_error_lex)
		return (parser_free_for_clause(list));
	return (list);
}
