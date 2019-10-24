/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwisoky <dwisoky@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 16:01:55 by dwisoky           #+#    #+#             */
/*   Updated: 2019/10/13 12:31:09 by dwisoky          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

/*
** Grammar rule
** list    : list separator_op and_or
**         |                   and_or
**         ;
*/

t_pars_list			*parser_free_list(t_pars_list *list)
{
	if (!list)
		return (NULL);
	parser_free_and_or(list->and_or);
	parser_free_list(list->next);
	free(list);
	return (NULL);
}

static t_pars_list	*parser_init_list(t_pars_list *list_down)
{
	t_pars_list		*list;

	list = (t_pars_list*)ft_xmemalloc(sizeof(t_pars_list));
	list->next = list_down;
	list->sep = 0;
	list->and_or = NULL;
	list->lex_begin = g_lex;
	list->lex_end = NULL;
	return (list);
}

t_pars_list			*parser_list(t_pars_list *list_down)
{
	t_pars_list	*list;

	if (!g_lex)
		return (NULL);
	list = parser_init_list(list_down);
	list->and_or = parser_and_or(NULL);
	if (g_error_lex)
		return (parser_free_list(list));
	if (!g_lex)
		return (list);
	if ((g_lex->type == JOB || g_lex->type == SEMI || g_lex->type == NEWLINE)
			&& g_lex->next && g_lex->next->type != NEWLINE)
	{
		list->sep = g_lex->type;
		g_lex = g_lex->next;
		list->lex_end = g_lex;
		return (parser_list(list));
	}
	list->lex_end = g_lex;
	return (list);
}
