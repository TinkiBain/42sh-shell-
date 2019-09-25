/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expr_logical_op.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwisoky <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/24 17:58:12 by dwisoky           #+#    #+#             */
/*   Updated: 2019/09/25 19:58:09 by dwisoky          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arifmetic.h"

size_t		expr_logical_op(void)
{
	size_t	left_value;
	size_t	right_value;
	int		type;

	left_value = expr_equal();
	if (g_error_arifmetic)
		return (0);
	if (g_lex_arif && g_lex_arif->type >= OR &&
			g_lex_arif->next->type <= LOGICAL_AND)
	{
		type = g_lex_arif->type;
		g_lex_arif = g_lex_arif->next;
		right_value = expr_digit();
		if (g_error_arifmetic)
			return (0);
		if (type == OR)
			return (left_value || right_value);
		else if (type == AND)
			return (left_value && right_value);
		else if (type == LOGICAL_OR)
			return (left_value | right_value);
		else
			return (left_value & right_value);
	}
	return (left_value);
}

/*	if (lex && (lex->type == DIGIT || lex->type == VAR) && lex->next
		   && lex->next->type >= OR && lex->next->type <= LOGICAL_AND)
	{
//		left_value = expr_get_value(lex);
		left_value = atoll(lex->lexem);
		and_or = lex->next->type;
		lex = lex->next->next;
		right_value = expr_logical_op(lex);
		if (and_or == OR)
			return (left_value || right_value);
		else if (and_or == AND)
			return (left_value && right_value);
		else if (and_or == LOGICAL_OR)
			return (left_value | right_value);
		return (left_value & right_value);	
	}
	else
		return (expr_equal(lex));
*/
