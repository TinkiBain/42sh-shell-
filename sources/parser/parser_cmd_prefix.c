/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_cmd_prefix.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggwin-go <ggwin-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/05 20:34:31 by ggwin-go          #+#    #+#             */
/*   Updated: 2019/07/09 21:57:39 by dwisoky          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static t_cmd_prefix	*init_cmd_prefix(t_lex	*lex)
{
	t_cmd_prefix	*cmd_pref;

	cmd_pref = (t_cmd_prefix*)ft_xmalloc(sizeof(t_cmd_prefix));
	if (lex->type & WORD)
	{
		cmd_pref->assignment_word = ft_strdup(lex->lexeme);
		cmd_pref->io_redir = NULL;
	}
	else
	{
		cmd_pref->assignment_word = NULL;
		cmd_pref->io_redir = parser_io_redirect(lex);
	}
	cmd_pref->cmd_pref = NULL;
	return (cmd_pref);
}

static int			parser_prefix_check(char *lexeme)
{
	if (*lexeme == '=')
		return (1);
	++lexeme;
	while (*lexeme)
	{
		if (*lexeme == '=' && *(lexeme + 1))
			return (0);
		++lexeme;
	}
	return (1);
}

t_lex				**parser_cmd_prefix(t_lex **lex, t_cmd_prefix **pref)
{
	t_lex			**tmp;

	while(*lex)
	{
		tmp = lex;
		if ((*lex)->type & WORD && (parser_prefix_check((*lex)->lexeme)))
			return (lex);
		*pref = init_cmd_prefix(*lex);
		pref = &(*pref)->cmd_pref;
		lex = &(*lex)->next;
		free_lex(tmp);
	}
	return (NULL);
}
