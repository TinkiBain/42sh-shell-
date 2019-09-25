/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arifmetic_lexer_simple_operations.c                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwisoky <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/23 19:14:34 by dwisoky           #+#    #+#             */
/*   Updated: 2019/09/24 19:34:33 by dwisoky          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arifmetic.h"

char	*arifmetic_lexer_module(char *str, t_lex **lex)
{
	++str;
	if (*str == '=')
	{
		++str;
		init_lex(MOD_ASSIGNMENT, NULL, lex);
	}
	else
		init_lex(MODULE, NULL, lex);
	return (str);
}

char	*arifmetic_lexer_division(char *str, t_lex **lex)
{
	++str;
	if (*str == '=')
	{
		++str;
		init_lex(DIV_ASSIGNMENT, NULL, lex);
	}
	else
		init_lex(DIVISION, NULL, lex);
	return (str);
}

char	*arifmetic_lexer_multi(char *str, t_lex **lex)
{
	++str;
	if (*str == '=')
	{
		++str;
		init_lex(MUL_ASSIGNMENT, NULL, lex);
	}
	else
		init_lex(MULTI, NULL, lex);
	return (str);
}

char	*arifmetic_lexer_minus(char *str, t_lex **lex)
{
	++str;
	if (*str == '=')
	{
		++str;
		init_lex(MIN_ASSIGNMENT, NULL, lex);
	}
	else if (*str == '-' && ft_isalpha(*(str + 1)))
	{
		++str;
		init_lex(PREFIX_MIN, NULL, lex);
	}
	else
		init_lex(MINUS, NULL, lex);
	return (str);
}

char	*arifmetic_lexer_plus(char *str, t_lex **lex)
{
	++str;
	if (*str == '=')
	{
		++str;
		init_lex(ADD_ASSIGNMENT, NULL, lex);
	}
	else if (*str == '+' && ft_isalpha(*(str + 1)))
	{
		++str;
		init_lex(PREFIX_ADD, NULL, lex);
	}
	else
		init_lex(PLUS, NULL, lex);
	return (str);
}
