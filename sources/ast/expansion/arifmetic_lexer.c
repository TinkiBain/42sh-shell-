/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arifmetic_lexer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwisoky <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/23 17:21:28 by dwisoky           #+#    #+#             */
/*   Updated: 2019/10/02 17:37:42 by dwisoky          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arifmetic.h"

char		*arifmetic_lexer_bracket(char *str, t_lex **lex)
{
	if (*str == '(')
		init_lex(LBRACKET_ARIF, ft_strdup("("), lex);
	else
		init_lex(RBRACKET_ARIF, ft_strdup(")"), lex);
	++str;
	return (str);
}

char		*arifmetic_lexer_not(char *str, t_lex **lex)
{
	++str;
	if (*str == '=')
	{
		++str;
		init_lex(NOT_EQUAL_IF, ft_strdup("!="), lex);
	}
	else
		init_lex(LOGICAL_NOT, ft_strdup("!"), lex);
	return (str);
}

t_lex		*arifmetic_lexer(char *str)
{
	t_lex	*lex;

	lex = NULL;
	while (*str)
	{
		if (ft_isspace(*str))
		{
			++str;
			continue ;
		}
		if (ft_isalpha(*str))
			str = arifmetic_lexer_var(str, &lex);
		else if (ft_isdigit(*str))
			str = arifmetic_lexer_digit(str, &lex);
		else if (*str == '(' || *str == ')')
			str = arifmetic_lexer_bracket(str, &lex);
		else if (*str == '!')
			str = arifmetic_lexer_not(str, &lex);
//		else if (*str == '?' && ++str)
//			init_lex(TERN_
		else
			str = arifmetic_lexer_check_token(str, &lex);
	}
	if (!lex)
		return (NULL);
	while (lex->back)
		lex = lex->back;
	return (lex);
}
