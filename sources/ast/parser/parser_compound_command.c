/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_compound_command.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwisoky <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 18:11:16 by dwisoky           #+#    #+#             */
/*   Updated: 2019/09/07 18:11:17 by dwisoky          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

/*
** Grammar rule
** compound_command : brace_group
**                	| subshell
**				    | for_clause
**					| case_clause
**					| if_clause
**				    | while_clause
**					| until_clause
**					;
*/

t_compound_cmd			*parser_free_compound_command(t_compound_cmd *list)
{
	if (!list)
		return (NULL);
	parser_free_compound_list(list->compound_list);
	free(list);
	return (NULL);
}

static t_compound_cmd	*parser_init_compound_command(void)
{
	t_compound_cmd	*list;

	list = (t_compound_cmd*)ft_xmalloc(sizeof(t_compound_cmd));
	list->compound_list = NULL;
	return (list);
}

t_compound_cmd			*parser_compound_command(void)
{
	t_compound_cmd	*list;

	if (!g_lex)
		return (NULL);
	list = parser_init_compound_command();
	if (g_lex->type == LBRACE)
		list->compound_list = parser_brace_group();
	else if (g_lex->type == WORD && ft_strequ(g_lex->lexem, "("))
		list->compound_list = parser_subshell();
	else
		return (parser_free_compound_command(list));
	return (list);
}
