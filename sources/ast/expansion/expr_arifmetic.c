/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expr_arifmetic.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwisoky <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/24 18:48:21 by dwisoky           #+#    #+#             */
/*   Updated: 2019/09/25 22:10:15 by dwisoky          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arifmetic.h"

size_t		expr_arifmetic(void)
{
	size_t	left_value;
	size_t	right_value;
	int		type;

	left_value = expr_arifmetic_mul();
	if (g_error_arifmetic)
		return (0);
	if (g_lex_arif && (g_lex_arif->type >= PLUS && g_lex_arif->type <= MINUS))
	{
		type = g_lex_arif->type;
		g_lex_arif = g_lex_arif->next;
		right_value = expr_logical_op();
		if (g_error_arifmetic)
			return (0);
		if (type == PLUS)
			return (left_value + right_value);
		else
			return (left_value - right_value);
	}
	return (left_value);
}
