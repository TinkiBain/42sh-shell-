/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_find_word.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwisoky <dwisoky@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/02 17:34:52 by dwisoky           #+#    #+#             */
/*   Updated: 2019/10/13 12:29:45 by dwisoky          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

char		*lexer_find_char(char *str, char c)
{
	++str;
	if (c == '\\' && *str)
		return (str);
	while (*str && *str != c)
	{
		if (*str == '\\' && c != '\'')
		{
			++str;
			if (!*str)
				return (str);
		}
		else if (*str == '$')
			str = lexer_find_dollar(str + 1);
		++str;
	}
	return (str);
}

char		*lexer_find_word(char *str, t_lex **lex)
{
	char	*begin;
	int		flag;

	begin = str;
	flag = 0;
	while (*str)
	{
		if (ft_isspace(*str))
			break ;
		else if (lexer_check_spec_symbol(*str) && (flag = 1))
			break ;
		if (*str == '\'' || *str == '"' || *str == '\\' || *str == '`')
			str = lexer_find_char(str, *str);
		if (*str == '$')
			str = lexer_find_dollar(str + 1);
		if (*str)
			++str;
	}
	begin = ft_xstrndup(begin, str - begin);
	init_lex(WORD, begin, lex);
	if (flag)
		--str;
	return (str);
}
