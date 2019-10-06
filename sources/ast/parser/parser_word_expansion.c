/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_word_expansion.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggwin-go <ggwin-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 19:19:20 by dwisoky           #+#    #+#             */
/*   Updated: 2019/10/06 15:37:32 by ggwin-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "sh.h"
#include "arifmetic.h"

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

static char	*parser_find_dollar(char *str)
{
	int		brackets;

	++str;
	brackets = 0;
	if (*str != '{' || *str != '(')
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
//	extern int	g_parser_expanison;
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
//	if (g_parser_expansion)
//		return (ft_strdup(begin));
//	if (*begin == '$')
//		return (arifmetic_exp(begin));
//	begin = tdq(ft_strdup(begin));
	return (ft_strdup(begin));
}
