/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_check_reserved_word.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwisoky <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/29 19:54:00 by dwisoky           #+#    #+#             */
/*   Updated: 2019/08/29 20:59:13 by dwisoky          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

char	*lexer_find_char(char *str, char c)
{
	++str;
	while (*str && *str != c)
	{
		if (*str == '\\' && c != '\'')
		{
			++str;
			if (!*str)
				return (str);
			++str;
		}
		++str;
	}
	return (str);
}

char	*lexer_check_reserved_word(char *str, t_lex **lex)
{
	char	*begin;

	begin = str;
	while (*str)
	{
		if (ft_isspace(*str))
			break ;
		else if (lexer_check_spec_symbol(*str))
			break ;
		if (*str == '\'' || *str == '"')
			str = lexer_find_char(str, *str);
		else if (*str == '\\')
		{
			++str;
			if (!*str)
				break ;
			++str;
		}
		++str;
	}
	init_lex(WORD, ft_strndup(begin, str - begin), lex);
	return (str);
}
