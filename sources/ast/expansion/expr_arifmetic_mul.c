/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expr_arifmetic_mul.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwisoky <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/24 19:17:09 by dwisoky           #+#    #+#             */
/*   Updated: 2019/09/25 20:43:31 by dwisoky          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arifmetic.h"

size_t		expr_check_div_null(size_t left_value, size_t right_value, int op)
{
	if (!right_value)
	{
		g_error_arifmetic = g_lex_arif;
		g_error_arifmetic->type = DIVISION_NULL;
		return (0);
	}
	if (op)
		return (left_value / right_value);
	return (left_value % right_value);
}

size_t		expr_arifmetic_mul(void)
{
	size_t	left_value;
	size_t	right_value;
	int		type;

	left_value = expr_prefix();
	if (g_error_arifmetic)
		return (0);
	if (g_lex_arif && g_lex_arif->type >= MULTI && g_lex_arif->type <= MODULE)
	{
		type = g_lex_arif->type;
		g_lex_arif = g_lex_arif->next;
		right_value = expr_logical_op();
		if (g_error_arifmetic)
			return (0);
		if (type == MULTI)
			return (left_value * right_value);
		else if (type == DIVISION)
			return (expr_check_div_null(left_value, right_value, 1));
		else
			return (expr_check_div_null(left_value, right_value, 0));
	}
	return (left_value);
}
