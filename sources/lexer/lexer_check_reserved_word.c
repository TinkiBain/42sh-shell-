/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_check_reserved_word.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwisoky <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/29 18:49:50 by dwisoky           #+#    #+#             */
/*   Updated: 2019/08/29 18:56:26 by dwisoky          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "new_lexer.h"

char		*lexer_find_symbol(char *str, char c)
{
	++str;
	while (*str && *str != c)
	{
		if (*str == '\\' && *str != c)
		{
			++str;
			if (!*str)
				break ;
			++str;
		}
		++str;
	}
	return (str);
}


char		*lexer_check_reserverd_word(char *str, t_lex **lex)
{
	char	*begin;

	begin = str;
	while (*str)
	{
		if (*str == '\'' || *str == '"')
			str = lexer_find_symbol(str, *str);
		if (*str == '\\')
		{
			++str;
			if (!*str)
				break ;
			++str;
		}
		++str;
	}
	init_lex(WORD, ft_strndup(begin, str - begin));
	return (str);
}
