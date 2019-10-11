/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_word_expansion.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jterry <jterry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 19:19:20 by dwisoky           #+#    #+#             */
/*   Updated: 2019/10/11 15:14:32 by gmelisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "sh.h"
#include "arifmetic.h"
#include "globing.h"

static char *parser_strchr(char *str, char c)
{
	if (!str)
		return (str);
	while (*str)
	{
		if (*str == c)
			return (str);
		++str;
	}
	return (str);
}

char	*parser_find_dollar(char *str)
{
	int		brackets;

	++str;
	brackets = 0;
	if (*str != '{' && *str != '(')
		return (str - 1);
	if (*str == '{')
		return (parser_strchr(str, '}'));
	if (*str == '(')
	{
		while (*str)
		{
			if (*str == '\'' || *str == '\\' || *str == '"')
				str = lexer_find_char(str, *str);
			if (*str == '(')
				brackets++;
			else if (*str == ')')
				brackets--;
			if (!brackets)
				return (str);
			++str;
		}
	}
	return (str);
}

char		*parser_word_expansion(char *str)
{
	char		*begin;
	char		c;

	begin = str;
	while (str && *str)
	{
		if (*str == '\'' || *str == '`' || *str == '"' || *str == '\\'
				|| *str == '$')
		{
			c = *str;
			if (*str == '$')
				str = parser_find_dollar(str);
			else
				str = lexer_find_char(str, *str);
			if (!*str)
			{
				begin = parser_recall_readline(c);
				str = begin;
			}
			else
				++str;
		}
		else
			++str;
		if (g_error_lex)
			return (NULL);
	}
	return (ft_xstrdup(begin));
}
