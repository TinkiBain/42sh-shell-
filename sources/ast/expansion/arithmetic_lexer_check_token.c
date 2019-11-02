/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arithmetic_lexer_check_token.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwisoky <dwisoky@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/23 18:20:00 by dwisoky           #+#    #+#             */
/*   Updated: 2019/11/02 20:14:06 by dwisoky          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arithmetic.h"

int			arithmetic_lexer_is_token(char str)
{
	if (str == '+' || str == '=' || str == '*' || str == '/' || str == '%'
			|| str == '<' || str == '>' || str == '&' || str == '|')
		return (1);
	return (0);
}

char		*arithmetic_lexer_check_token(char *str, t_lex **lex)
{
	if (*str == '+')
		return (arithmetic_lexer_plus(str, lex));
	else if (*str == '-')
		return (arithmetic_lexer_minus(str, lex));
	else if (*str == '=')
		return (arithmetic_lexer_assignment(str, lex));
	else if (*str == '*')
		return (arithmetic_lexer_multi(str, lex));
	else if (*str == '/')
		return (arithmetic_lexer_division(str, lex));
	else if (*str == '%')
		return (arithmetic_lexer_module(str, lex));
	else if (*str == '<')
		return (arithmetic_lexer_less(str, lex));
	else if (*str == '>')
		return (arithmetic_lexer_great(str, lex));
	else if (*str == '&')
		return (arithmetic_lexer_and(str, lex));
	else if (*str == '|')
		return (arithmetic_lexer_or(str, lex));
	return (NULL);
}
