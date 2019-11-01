/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expr_relat_op.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwisoky <dwisoky@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/29 19:26:44 by dwisoky           #+#    #+#             */
/*   Updated: 2019/11/02 01:28:44 by dwisoky          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arithmetic.h"

long		expr_relat_op(void)
{
	long	left_value;
	long	right_value;
	int		type;

	left_value = expr_shift();
	if (g_error_arithmetic)
		return (0);
	while (g_lex_arif && g_lex_arif->type >= LESS_IF
			&& g_lex_arif->type <= GREAT_EQ)
	{
		type = g_lex_arif->type;
		g_lex_arif = g_lex_arif->next;
		right_value = expr_shift();
		if (g_error_arithmetic)
			return (0);
		if (type == LESS_IF)
			left_value = left_value < right_value;
		else if (type == LESS_EQ)
			left_value = left_value <= right_value;
		else if (type == GREAT_IF)
			left_value = left_value > right_value;
		else
			left_value = left_value >= right_value;
	}
	return (left_value);
}
