/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arifmetic_lexer_logical_op.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwisoky <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/23 20:36:41 by dwisoky           #+#    #+#             */
/*   Updated: 2019/09/24 17:01:34 by dwisoky          ###   ########.fr       */
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
			init_lex(DGR_ASSIGNMENT, NULL, lex);
		}
		else
			init_lex(RIGHT_SHIFT, NULL, lex);
	}
	else if (*str == '=')
	{
		++str;
		init_lex(GREAT_EQ, NULL, lex);
	}
	else
		init_lex(GREAT_IF, NULL, lex);
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
			init_lex(DLS_ASSIGNMENT, NULL, lex);
		}
		else
			init_lex(LEFT_SHIFT, NULL, lex);
	}
	else if (*str == '=')
	{
		++str;
		init_lex(LESS_EQ, NULL, lex);
	}
	else
		init_lex(LESS_IF, NULL, lex);
	return (str);
}

char		*arifmetic_lexer_assignment(char *str, t_lex **lex)
{
	++str;
	if (*str == '=')
	{
		++str;
		init_lex(EQUAL_IF, NULL, lex);
	}
	else
		init_lex(ASSIGNMENT, NULL, lex);
	return (str);
}

char		*arifmetic_lexer_or(char *str, t_lex **lex)
{
	++str;
	if (*str == '|')
	{
		++str;
		init_lex(OR, NULL, lex);
	}
	else if (*str == '=')
	{
		++str;
		init_lex(OR_ASSIGNMENT, NULL, lex);
	}
	else
		init_lex(LOGICAL_OR, NULL, lex);
	return (str);
}

char		*arifmetic_lexer_and(char *str, t_lex **lex)
{
	++str;
	if (*str == '&')
	{
		++str;
		init_lex(AND, NULL, lex);
	}
	else if (*str == '=')
	{
		++str;
		init_lex(AND_ASSIGNMENT, NULL, lex);
	}
	else
		init_lex(LOGICAL_AND, NULL, lex);
	return (str);
}
