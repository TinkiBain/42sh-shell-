/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_word_expansion.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwisoky <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 19:19:20 by dwisoky           #+#    #+#             */
/*   Updated: 2019/09/24 15:27:06 by dwisoky          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "sh.h"
#include "arifmetic.h"

char		*parser_word_expansion(char *str)
{
	extern int	g_parser_expanison;
	char		*begin;
	char		c;

	begin = str;
	while (str && *str)
	{
		if (*str == '\'' || *str == '`' || *str == '"' || *str == '\\')
		{
			c = *str;
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
	if (g_parser_expansion)
		return (ft_strdup(begin));
	if (*begin == '$')
		return (arifmetic_exp(begin));
	begin = tdq(ft_strdup(begin)); 
	return (begin);
}
