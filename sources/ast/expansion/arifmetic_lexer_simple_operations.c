/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arifmetic_lexer_simple_operations.c                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwisoky <dwisoky@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/23 19:14:34 by dwisoky           #+#    #+#             */
/*   Updated: 2019/10/15 17:24:58 by dwisoky          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arifmetic.h"

char	*arifmetic_lexer_module(char *str, t_lex **lex)
{
	++str;
	if (*str == '=')
	{
		++str;
		init_lex(MOD_ASSIGNMENT, ft_xstrdup("%="), lex);
	}
	else
		init_lex(MODULE, ft_xstrdup("%"), lex);
	return (str);
}

char	*arifmetic_lexer_division(char *str, t_lex **lex)
{
	++str;
	if (*str == '=')
	{
		++str;
		init_lex(DIV_ASSIGNMENT, ft_xstrdup("/="), lex);
	}
	else
		init_lex(DIVISION, ft_xstrdup("/"), lex);
	return (str);
}

char	*arifmetic_lexer_multi(char *str, t_lex **lex)
{
	++str;
	if (*str == '=')
	{
		++str;
		init_lex(MUL_ASSIGNMENT, ft_xstrdup("*="), lex);
	}
	else
		init_lex(MULTI, ft_xstrdup("*"), lex);
	return (str);
}

char	*arifmetic_lexer_minus(char *str, t_lex **lex)
{
	++str;
	if (*str == '=')
	{
		++str;
		init_lex(MIN_ASSIGNMENT, ft_xstrdup("-="), lex);
	}
	else if (*str == '-' && ft_isalpha(*(str + 1)))
	{
		++str;
		init_lex(PREFIX_MIN, ft_xstrdup("--"), lex);
	}
	else
		init_lex(MINUS, ft_xstrdup("-"), lex);
	return (str);
}

char	*arifmetic_lexer_plus(char *str, t_lex **lex)
{
	++str;
	if (*str == '=')
	{
		++str;
		init_lex(ADD_ASSIGNMENT, ft_xstrdup("+="), lex);
	}
	else if (*str == '+' && ft_isalpha(*(str + 1)))
	{
		++str;
		init_lex(PREFIX_ADD, ft_xstrdup("++"), lex);
	}
	else
		init_lex(PLUS, ft_xstrdup("+"), lex);
	return (str);
}
