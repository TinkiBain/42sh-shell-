/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_while_clause.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwisoky <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 20:00:35 by dwisoky           #+#    #+#             */
/*   Updated: 2019/09/10 21:20:54 by dwisoky          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

/*
** Grammar rule
** while_clause     : While compound_list do_group
**                  ;
** OR
** until_clause     : Until compound_list do_group
**                  ;
*/

t_while_clause			*parser_free_while_clause(t_while_clause *list)
{
	if (!list)
		return (NULL);
	parser_free_compound_list(list->compound_list);
	parser_free_compound_list(list->do_group);
	free(list);
	return (NULL);
}

static t_while_clause	*parser_init_while_clause(void)
{
	t_while_clause		*list;

	list = (t_while_clause*)ft_xmalloc(sizeof(t_while_clause));
	list->compound_list = NULL;
	list->do_group = NULL;
	return (list);	
}

t_while_clause			*parser_while_clause(void)
{
	t_while_clause		*list;

	list = parser_init_while_clause();
	g_lex = g_lex->next;
	list->compound_list = parser_compound_list();
	if (g_error_lex)
		return (parser_free_while_clause(list));
	list->do_group = parser_do_group();
	if (g_error_lex)
		return (parser_free_while_clause(list));
	return (list);
}
