/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arifmetic_lexer_logical_op.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwisoky <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/23 20:36:41 by dwisoky           #+#    #+#             */
/*   Updated: 2019/10/02 17:02:21 by dwisoky          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arifmetic.h"

char		*arifmetic_lexer_great(char *str, t_lex **lex)
{
	++str;
	if (*str == '>')
	{
		++str;
		if (*str == '=')
		{
			++str;
			init_lex(DGR_ASSIGNMENT, ft_strdup(">>="), lex);
		}
		else
			init_lex(RIGHT_SHIFT, ft_strdup(">>"), lex);
	}
	else if (*str == '=')
	{
		++str;
		init_lex(GREAT_EQ, ft_strdup(">="), lex);
	}
	else
		init_lex(GREAT_IF, ft_strdup(">"), lex);
	return (str);
}

char		*arifmetic_lexer_less(char *str, t_lex **lex)
{
	++str;
	if (*str == '<')
	{
		++str;
		if (*str == '=')
		{
			++str;
			init_lex(DLS_ASSIGNMENT, ft_strdup("<<="), lex);
		}
		else
			init_lex(LEFT_SHIFT, ft_strdup("<<"), lex);
	}
	else if (*str == '=')
	{
		++str;
		init_lex(LESS_EQ, ft_strdup("<="), lex);
	}
	else
		init_lex(LESS_IF, ft_strdup("<"), lex);
	return (str);
}

char		*arifmetic_lexer_assignment(char *str, t_lex **lex)
{
	++str;
	if (*str == '=')
	{
		++str;
		init_lex(EQUAL_IF, ft_strdup("=="), lex);
	}
	else
		init_lex(ASSIGNMENT, ft_strdup("="), lex);
	return (str);
}

char		*arifmetic_lexer_or(char *str, t_lex **lex)
{
	++str;
	if (*str == '|')
	{
		++str;
		init_lex(OR, ft_strdup("||"), lex);
	}
	else if (*str == '=')
	{
		++str;
		init_lex(OR_ASSIGNMENT, ft_strdup("|="), lex);
	}
	else
		init_lex(LOGICAL_OR, ft_strdup("|"), lex);
	return (str);
}

char		*arifmetic_lexer_and(char *str, t_lex **lex)
{
	++str;
	if (*str == '&')
	{
		++str;
		init_lex(AND, ft_strdup("&&"), lex);
	}
	else if (*str == '=')
	{
		++str;
		init_lex(AND_ASSIGNMENT, ft_strdup("&="), lex);
	}
	else
		init_lex(LOGICAL_AND, ft_strdup("&"), lex);
	return (str);
}