/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_find_eq.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwisoky <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 22:08:09 by dwisoky           #+#    #+#             */
/*   Updated: 2019/09/13 22:11:28 by dwisoky          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int			parser_find_eq(void)
{
	char	*str;

	if (g_lex->type != WORD)
		return (0);
	str = g_lex->lexem;
	while (*str)
	{
		if (*str == '=')
			return (1);
		else if (*str == '"' || *str == '\\' || *str == '\'')
			str = lexer_find_char(str, *str);
		else
			++str;
	}
	return (0);
}
