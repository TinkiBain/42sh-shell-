/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expr_equal.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwisoky <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/24 18:08:42 by dwisoky           #+#    #+#             */
/*   Updated: 2019/09/25 19:58:53 by dwisoky          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arifmetic.h"

size_t		expr_equal(void)
{
	size_t	left_value;
	size_t	right_value;
	int		type;

	left_value = expr_less_great();
	if (g_lex_arif && (g_lex_arif->type == EQUAL_IF
				|| g_lex_arif->type == NOT_EQUAL_IF))
	{
		type = g_lex_arif->type;
		g_lex_arif = g_lex_arif->next;
		right_value = expr_logical_op();
		if (g_error_arifmetic)
			return (0);
		if (type == EQUAL_IF)
			return ((right_value == left_value) ? 1 : 0);
		else
			return ((right_value != left_value) ? 1 : 0);
	}
	return (left_value);
}

/*
	if (lex && (lex->type == DIGIT || lex->type == VAR) && lex->next &&
			(lex->next->type == EQUAL_IF || lex->next->type == NOT_EQUAL_IF))
	{
		left_value = atoll(lex->lexem);
		type = lex->next->type;
		lex = lex->next->next;
		right_value = expr_logical_op(lex);
		if (g_error_arifmetic)
			return (0);
		if (type == EQUAL_IF)
			return ((right_value == left_value) ? 1 : 0);
		else
			return((right_value != left_value) ? 1 : 0);
	}
	return (expr_less_great(lex));
*/
