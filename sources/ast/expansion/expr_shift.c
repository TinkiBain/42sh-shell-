/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expr_shift.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwisoky <dwisoky@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/29 19:40:36 by dwisoky           #+#    #+#             */
/*   Updated: 2019/10/11 18:54:06 by dwisoky          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arifmetic.h"

long		expr_shift(void)
{
	long	right_value;
	long	left_value;
	int		type;

	left_value = expr_additive();
	if (g_error_arifmetic)
		return (0);
	while (g_lex_arif && g_lex_arif->type >= LEFT_SHIFT &&
			g_lex_arif->type <= RIGHT_SHIFT)
	{
		type = g_lex_arif->type;
		g_lex_arif = g_lex_arif->next;
		right_value = expr_additive();
		if (g_error_arifmetic)
			return (0);
		if (type == LEFT_SHIFT)
			left_value = left_value << right_value;
		else
			left_value = right_value >> right_value;
	}
	return (left_value);
}
