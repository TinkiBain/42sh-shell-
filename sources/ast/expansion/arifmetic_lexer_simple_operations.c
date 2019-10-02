/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arifmetic_lexer_simple_operations.c                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwisoky <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/23 19:14:34 by dwisoky           #+#    #+#             */
/*   Updated: 2019/10/02 16:46:16 by dwisoky          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arifmetic.h"

char	*arifmetic_lexer_module(char *str, t_lex **lex)
{
	++str;
	if (*str == '=')
	{
		++str;
		init_lex(MOD_ASSIGNMENT, ft_strdup("%="), lex);
	}
	else
		init_lex(MODULE, ft_strdup("%"), lex);
	return (str);
}

char	*arifmetic_lexer_division(char *str, t_lex **lex)
{
	++str;
	if (*str == '=')
	{
		++str;
		init_lex(DIV_ASSIGNMENT, ft_strdup("/="), lex);
	}
	else
		init_lex(DIVISION, ft_strdup("/"), lex);
	return (str);
}

char	*arifmetic_lexer_multi(char *str, t_lex **lex)
{
	++str;
	if (*str == '=')
	{
		++str;
		init_lex(MUL_ASSIGNMENT, ft_strdup("*="), lex);
	}
	else
		init_lex(MULTI, ft_strdup("*"), lex);
	return (str);
}

char	*arifmetic_lexer_minus(char *str, t_lex **lex)
{
	++str;
	if (*str == '=')
	{
		++str;
		init_lex(MIN_ASSIGNMENT, ft_strdup("-="), lex);
	}
	else if (*str == '-' && ft_isalpha(*(str + 1)))
	{
		++str;
		init_lex(PREFIX_MIN, ft_strdup("--"), lex);
	}
	else
		init_lex(MINUS, ft_strdup("-"), lex);
	return (str);
}

char	*arifmetic_lexer_plus(char *str, t_lex **lex)
{
	++str;
	if (*str == '=')
	{
		++str;
		init_lex(ADD_ASSIGNMENT, ft_strdup("+="), lex);
	}
	else if (*str == '+' && ft_isalpha(*(str + 1)))
	{
		++str;
		init_lex(PREFIX_ADD, ft_strdup("++"), lex);
	}
	else
		init_lex(PLUS, ft_strdup("+"), lex);
	return (str);
}
