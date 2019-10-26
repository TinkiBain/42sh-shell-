/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_check_alias.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwisoky <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 16:29:56 by dwisoky           #+#    #+#             */
/*   Updated: 2019/10/26 21:01:56 by dwisoky          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "sh.h"

char		*parser_get_alias(char *str)
{
	extern int		g_if_alias;
	extern t_alias	*g_alias;
	t_alias			*tmp;

	if (!str)
		return (NULL);
	tmp = g_alias;
	while (tmp)
	{
		if (!tmp->head)
			return ("\0");
		if (ft_strequ(tmp->head, str))
		{
			g_if_alias = 1;
			break ;
		}
		tmp = tmp->next;
	}
	if (!tmp)
		return (NULL);
	return (tmp->body_alias);
}

char		*parser_check_alias(char *str)
{
	t_lex	*lex;
	char	*tmp;

	if (!(tmp = parser_get_alias(str)))
		return (str);
	if (!*tmp)
	{
		g_lex = g_lex->next;
		return (parser_check_alias(g_lex->lexem));
	}
	lex = lexer(tmp);
	lex = lex->back;
	free(lex->next);
	lex->next = g_lex->next;
	while (lex->back)
		lex = lex->back;
	g_lex->type = lex->type;
	if (g_lex->lexem)
		free(g_lex->lexem);
	g_lex->lexem = lex->lexem;
	g_lex->next = lex->next;
	free(lex);
	if (g_lex->type == WORD)
		return (g_lex->lexem);
	return (NULL);
}
