/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arithmetic_lexer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwisoky <dwisoky@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/23 17:21:28 by dwisoky           #+#    #+#             */
/*   Updated: 2019/10/30 19:20:34 by dwisoky          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arithmetic.h"

char		*arithmetic_lexer_bracket(char *str, t_lex **lex)
{
	if (*str == '(')
		init_lex(LBRACKET_ARIF, ft_xstrdup("("), lex);
	else
		init_lex(RBRACKET_ARIF, ft_xstrdup(")"), lex);
	++str;
	return (str);
}

char		*arithmetic_lexer_not(char *str, t_lex **lex)
{
	++str;
	if (*str == '=')
	{
		++str;
		init_lex(NOT_EQUAL_IF, ft_xstrdup("!="), lex);
	}
	else
		init_lex(LOGICAL_NOT, ft_xstrdup("!"), lex);
	return (str);
}

t_lex		*arithmetic_lexer(char *str)
{
	t_lex	*lex;
	char	*begin;

	lex = NULL;
	while (str && *str)
	{
		begin = str;
		while (ft_isspace(*str))
			++str;
		if (ft_isalpha(*str))
			str = arithmetic_lexer_var(str, &lex);
		else if (ft_isdigit(*str))
			str = arithmetic_lexer_digit(str, &lex);
		else if (*str == '(' || *str == ')')
			str = arithmetic_lexer_bracket(str, &lex);
		else if (*str == '!')
			str = arithmetic_lexer_not(str, &lex);
		else
			str = arithmetic_lexer_check_token(str, &lex);
	}
	if (!str)
		init_lex(DIGIT, begin, &g_error_arithmetic);
	while (lex && lex->back)
		lex = lex->back;
	return (lex);
}
