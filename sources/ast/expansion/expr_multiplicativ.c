/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expr_multiplicativ.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwisoky <dwisoky@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 17:13:37 by dwisoky           #+#    #+#             */
/*   Updated: 2019/11/02 01:28:39 by dwisoky          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arithmetic.h"

long		expr_multiplicativ(void)
{
	long	left_value;
	long	right_value;
	int		type;

	left_value = expr_prefix();
	if (g_error_arithmetic)
		return (0);
	while (g_lex_arif && g_lex_arif->type >= MULTI
			&& g_lex_arif->type <= MODULE)
	{
		type = g_lex_arif->type;
		g_lex_arif = g_lex_arif->next;
		right_value = expr_prefix();
		if (right_value == 0 && type != MULTI && !g_error_arithmetic)
			init_lex(DIVISION_NULL, NULL, &g_error_arithmetic);
		if (g_error_arithmetic)
			return (0);
		if (type == MULTI)
			left_value *= right_value;
		else if (type == DIVISION)
			left_value /= right_value;
		else
			left_value %= right_value;
	}
	return (left_value);
}
