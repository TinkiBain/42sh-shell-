/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arithmetic_lexer_logical_op.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwisoky <dwisoky@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/23 20:36:41 by dwisoky           #+#    #+#             */
/*   Updated: 2019/10/15 17:25:01 by dwisoky          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arithmetic.h"

char		*arithmetic_lexer_great(char *str, t_lex **lex)
{
	++str;
	if (*str == '>')
	{
		++str;
		if (*str == '=')
		{
			++str;
			init_lex(DGR_ASSIGNMENT, ft_xstrdup(">>="), lex);
		}
		else
			init_lex(RIGHT_SHIFT, ft_xstrdup(">>"), lex);
	}
	else if (*str == '=')
	{
		++str;
		init_lex(GREAT_EQ, ft_xstrdup(">="), lex);
	}
	else
		init_lex(GREAT_IF, ft_xstrdup(">"), lex);
	return (str);
}

char		*arithmetic_lexer_less(char *str, t_lex **lex)
{
	++str;
	if (*str == '<')
	{
		++str;
		if (*str == '=')
		{
			++str;
			init_lex(DLS_ASSIGNMENT, ft_xstrdup("<<="), lex);
		}
		else
			init_lex(LEFT_SHIFT, ft_xstrdup("<<"), lex);
	}
	else if (*str == '=')
	{
		++str;
		init_lex(LESS_EQ, ft_xstrdup("<="), lex);
	}
	else
		init_lex(LESS_IF, ft_xstrdup("<"), lex);
	return (str);
}

char		*arithmetic_lexer_assignment(char *str, t_lex **lex)
{
	++str;
	if (*str == '=')
	{
		++str;
		init_lex(EQUAL_IF, ft_xstrdup("=="), lex);
	}
	else
		init_lex(ASSIGNMENT, ft_xstrdup("="), lex);
	return (str);
}

char		*arithmetic_lexer_or(char *str, t_lex **lex)
{
	++str;
	if (*str == '|')
	{
		++str;
		init_lex(OR, ft_xstrdup("||"), lex);
	}
	else if (*str == '=')
	{
		++str;
		init_lex(OR_ASSIGNMENT, ft_xstrdup("|="), lex);
	}
	else
		init_lex(LOGICAL_OR, ft_xstrdup("|"), lex);
	return (str);
}

char		*arithmetic_lexer_and(char *str, t_lex **lex)
{
	++str;
	if (*str == '&')
	{
		++str;
		init_lex(AND, ft_xstrdup("&&"), lex);
	}
	else if (*str == '=')
	{
		++str;
		init_lex(AND_ASSIGNMENT, ft_xstrdup("&="), lex);
	}
	else
		init_lex(LOGICAL_AND, ft_xstrdup("&"), lex);
	return (str);
}
