/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_term.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggwin-go <ggwin-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 18:29:18 by dwisoky           #+#    #+#             */
/*   Updated: 2019/09/23 14:08:52 by ggwin-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

/*
** Grammar rule
** term             : term separator and_or
**                  |                and_or
**                  ;
*/

t_term			*parser_free_term(t_term *list)
{
	if (!list)
		return (NULL);
	parser_free_and_or(list->and_or);
	parser_free_term(list->next);
	free(list);
	return (NULL);
}

static t_term	*parser_init_term(t_term *list_down)
{
	t_term		*list;

	list = (t_term*)ft_xmalloc(sizeof(t_term));
	list->next = list_down;
	list->separator = 0;
	list->and_or = NULL;
	return (list);
}

t_term			*parser_term(t_term *list_down)
{
	t_term		*list;

	if (!g_lex)
		return (NULL);
	list = parser_init_term(list_down);
	list->and_or = parser_and_or(NULL);
	if (g_error_lex)
		return (parser_free_term(list));
	if (!g_lex)
		return (list);
	if (!(list->separator = parser_separator()))
		return (list);
	if ((g_lex->type == WORD && parser_check_reserved_words())
			|| g_lex->type == RBRACKET || g_lex->type == DSEMI)
		return (list);
	return (parser_term(list));
}
