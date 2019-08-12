/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_get_token.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggwin-go <ggwin-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/29 17:30:53 by dwisoky           #+#    #+#             */
/*   Updated: 2019/08/11 17:24:26 by jterry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

int			ft_isspec(char c)
{
	if (c == ';' || c == '|' || c == '<' || c == '>' || c == '&')
		return (1);
	return (0);
}

char		*lexer_find_simbol(char *str, char c)
{
	while (*str)
	{
		if (c != '\'' && *str == '\\')
		{
			++str;
			if (*str)
				++str;
			else
				return (str);
		}
		if (*str == c)
			return (str + 1);
		++str;
	}
	return (str);
}

size_t		lexer_check_word(char *str, t_lex **lex)
{
	char	*begin;

	begin = str;
	while (*str && !ft_isspace(*str) && !ft_isspec(*str))
	{
		if (*str == '"')
			str = lexer_find_simbol(++str, '"');
		else if (*str == '\'')
			str = lexer_find_simbol(++str, '\'');
		else if (*str == '\\')
		{
			++str;
			if (*str)
				++str;
			else
				break ;
		}
		else
			++str;
	}
	(*lex)->lexeme = ft_strndup(begin, str - begin);
	(*lex)->type = WORD;
	return (str - begin);
}

char		*lexer_get_token(char *str, t_lex **lex)
{
	size_t	i;

	if ((*str == '&'|| *str == '|') && (i = lexer_and_or(str, lex)))
		return (str + i);
	else if ((i = lexer_check_redir(str, lex)))
		return (str + i);
	i = lexer_check_word(str, lex);
	return (str + i);
}
