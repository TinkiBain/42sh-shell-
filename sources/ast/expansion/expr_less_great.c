/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expr_less_great.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwisoky <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/24 18:20:55 by dwisoky           #+#    #+#             */
/*   Updated: 2019/09/25 20:07:02 by dwisoky          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arifmetic.h"

size_t		expr_less_great(void)
{
	size_t	left_value;
	size_t	right_value;
	int		type;

	left_value = expr_shift_bits();
	if (g_error_arifmetic)
		return (0);
	if (g_lex_arif && (g_lex_arif->type >= LESS_IF &&
				g_lex_arif->type <= GREAT_EQ))
	{
		type = g_lex_arif->type;
		g_lex_arif = g_lex_arif->next;
		right_value = expr_logical_op();
		if (g_error_arifmetic)
			return (0);
		if (type == LESS_IF)
			return (left_value < right_value);
		else if (type == LESS_EQ)
			return (left_value <= right_value);
		else if (type == GREAT_IF)
			return (left_value > right_value);
		return (left_value >= right_value);
	}
	return (left_value);
}
