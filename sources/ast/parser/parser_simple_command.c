/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_simple_command.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwisoky <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 18:39:39 by dwisoky           #+#    #+#             */
/*   Updated: 2019/09/13 16:09:36 by dwisoky          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

/*
** Grammar rule
** simple_command   : cmd_prefix cmd_word cmd_suffix
**                  | cmd_prefix cmd_word
**	                | cmd_prefix
**                  | cmd_name cmd_suffix
**                  | cmd_name
**	                ;
*/

static char				*parser_simple_command_take_name(void)
{
	char		*tmp;

	if (!g_lex)
		return (NULL);
	if (g_lex->type == WORD)
	{
		tmp = parser_check_alias(g_lex->lexem);
		if (tmp)
			g_lex = g_lex->next;
		else
			return (NULL);
		return (ft_strdup(tmp));
	}
	return (NULL);
}

t_simple_cmd			*parser_free_simple_command(t_simple_cmd *list)
{
	if (!list)
		return (NULL);
	parser_free_cmd_prefix(list->cmd_pref);
	parser_free_cmd_suffix(list->cmd_suf);
	if (list->cmd_word)
		free(list->cmd_word);
	if (list->cmd_name)
		free(list->cmd_name);
	free(list);
	return (NULL);
}

static t_simple_cmd		*parser_init_simple_command(void)
{
	t_simple_cmd		*list;

	list = (t_simple_cmd*)ft_xmalloc(sizeof(t_simple_cmd));
	list->cmd_pref = NULL;
	list->cmd_name = NULL;
	list->cmd_word = NULL;
	list->cmd_suf = NULL;
	list->lex_begin = g_lex;
	list->lex_end = NULL;
	return (list);
}

t_simple_cmd			*parser_simple_command(void)
{
	t_simple_cmd		*list;

	if (parser_check_reserved_words())
		return (NULL);
	list = parser_init_simple_command();
	list->cmd_pref = parser_cmd_prefix();
	if (list->cmd_pref)
		list->cmd_word = parser_simple_command_take_name();
	else
		list->cmd_name = parser_simple_command_take_name();
	list->cmd_suf = parser_cmd_suffix();
	list->lex_end = g_lex;
	if (!list->cmd_pref && !list->cmd_name)
	{
		g_error_lex = g_lex;
		return (parser_free_simple_command(list));
	}
	return (list);
}
