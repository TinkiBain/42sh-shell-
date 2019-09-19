/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_find_dollar.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwisoky <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/02 17:29:24 by dwisoky           #+#    #+#             */
/*   Updated: 2019/09/19 18:03:36 by dwisoky          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

char		*lexer_find_dollar(char *str)
{
	int		count_bracket;
	int		arifmetic;
	char	bracket_open;
	char	bracket_close;

	count_bracket = 1;
	arifmetic = 0;
	if (*str != '{' && *str != '(')
		return (str - 1);
	bracket_open = *str;
	if (*str == '(')
		bracket_close = ')';
	else
		bracket_close = '}';
	if (*str == '(' && *(str + 1) == '(')
		count_bracket = 2;
	while (*str++ && count_bracket)
	{
		if (*str == '\\' || *str == '\'' || *str == '"')
			str = lexer_find_char(str, *str);
		if (*str == bracket_close)
			--count_bracket;
	}
	str = (count_bracket) ? str : str - 1;
	return (str);
}
