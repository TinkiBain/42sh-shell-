/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_check_alias.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwisoky <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 16:29:56 by dwisoky           #+#    #+#             */
/*   Updated: 2019/09/12 19:56:19 by dwisoky          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "sh.h"

char		*parser_get_alias(char *str)
{
	extern t_alias	*g_alias;
	t_alias			*tmp;

	tmp = g_alias;
	while (tmp)
	{
		if (ft_strequ(tmp->head, str))
			break ;
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
	printf("%s\n", tmp);
	lex = lexer(tmp);
	lex = lex->back;
	free(lex->next);
	lex->next = g_lex->next;
	while (lex->back)
		lex = lex->back;
	if (g_lex->back)
		g_lex->back->next = lex;
	else
		g_lex->next = lex;
	g_lex = lex;
	if (lex->type == WORD)
		return (lex->lexem);
	return (NULL);
}
