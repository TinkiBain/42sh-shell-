/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_command.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwisoky <dwisoky@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 15:18:15 by dwisoky           #+#    #+#             */
/*   Updated: 2019/10/13 12:30:23 by dwisoky          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

/*
** Grammar rule
** command          : simple_command
**                  | compound_command
**                  | compound_command redirect_list
**                  | function_definition
**                  ;
*/

t_command			*parser_free_command(t_command *list)
{
	if (!list)
		return (NULL);
	parser_free_simple_command(list->simple_command);
	parser_free_compound_command(list->compound_command);
	parser_free_redirect_list(list->redirect_list);
	parser_free_function_definition(list->function_definition);
	free(list);
	return (NULL);
}

static t_command	*parser_init_command(void)
{
	t_command		*list;

	list = (t_command*)ft_xmemalloc(sizeof(t_command));
	list->simple_command = NULL;
	list->compound_command = NULL;
	list->function_definition = NULL;
	list->redirect_list = NULL;
	return (list);
}

t_command			*parser_command(void)
{
	t_command	*list;

	list = parser_init_command();
	if ((list->compound_command = parser_compound_command()))
	{
		list->redirect_list = parser_redirect_list(NULL);
		return (list);
	}
	else if (g_lex->next && g_lex->next->type == LBRACKET &&
			!parser_find_eq())
		list->function_definition = parser_function_definition();
	else
		list->simple_command = parser_simple_command();
	if (g_error_lex)
		return (parser_free_command(list));
	return (list);
}
