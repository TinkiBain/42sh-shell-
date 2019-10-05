/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arifmetic_lexer_check_token.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwisoky <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/23 18:20:00 by dwisoky           #+#    #+#             */
/*   Updated: 2019/10/03 16:32:14 by dwisoky          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arifmetic.h"

char		*arifmetic_lexer_check_token(char *str, t_lex **lex)
{
	if (*str == '+')
		return (arifmetic_lexer_plus(str, lex));
	else if (*str == '-')
		return (arifmetic_lexer_minus(str, lex));
	else if (*str == '=')
		return (arifmetic_lexer_assignment(str, lex));
	else if (*str == '*')
		return (arifmetic_lexer_multi(str, lex));
	else if (*str == '/')
		return (arifmetic_lexer_division(str, lex));
	else if (*str == '%')
		return (arifmetic_lexer_module(str, lex));
	else if (*str == '<')
		return (arifmetic_lexer_less(str, lex));
	else if (*str == '>')
		return (arifmetic_lexer_great(str, lex));
	else if (*str == '&')
		return (arifmetic_lexer_and(str, lex));
	else if (*str == '|')
		return (arifmetic_lexer_or(str, lex));
	return (NULL);
}
