/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expr_shift_bits.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwisoky <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/24 18:42:04 by dwisoky           #+#    #+#             */
/*   Updated: 2019/09/25 20:01:22 by dwisoky          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arifmetic.h"

size_t		expr_shift_bits(void)
{
	size_t	left_value;
	size_t	right_value;
	int		type;

	left_value = expr_arifmetic();
	if (g_error_arifmetic)
		return (0);
	if (g_lex_arif && (g_lex_arif->type == LEFT_SHIFT ||
				g_lex_arif->type == RIGHT_SHIFT))
	{
		type = g_lex_arif->type;
		g_lex_arif = g_lex_arif->next;
		right_value = expr_logical_op();
		if (g_error_arifmetic)
			return (0);
		if (type == LEFT_SHIFT)
			return (left_value << right_value);
		else
			return (left_value >> right_value);
	}
	return (left_value);
}
/*
if (lex && (lex->type == DIGIT || lex->type == VAR) && lex->next &&
		(lex->next->type == LEFT_SHIFT || lex->next->type == RIGHT_SHIFT))
{
	left_value = atoll(lex->lexem);
	type = lex->next->type;
	lex = lex->next->next;
	right_value = expr_logical_op(lex);
	if (g_error_arifmetic)
		return (0);
	if (type == LEFT_SHIFT)
		return (left_value << right_value);
	else
		return (left_value >> right_value);
}
return (expr_arifmetic(lex));
*/
