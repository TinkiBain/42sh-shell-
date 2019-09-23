/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_word_expansion.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggwin-go <ggwin-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 19:19:20 by dwisoky           #+#    #+#             */
/*   Updated: 2019/09/23 14:07:22 by ggwin-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "sh.h"

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
	begin = tdq(ft_strdup(begin));
	return (begin);
}
