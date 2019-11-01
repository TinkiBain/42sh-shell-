/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expr_additive.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwisoky <dwisoky@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/29 19:51:00 by dwisoky           #+#    #+#             */
/*   Updated: 2019/11/02 01:28:11 by dwisoky          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arithmetic.h"

long		expr_additive(void)
{
	long	left_value;
	long	right_value;
	int		type;

	left_value = expr_multiplicativ();
	if (g_error_arithmetic)
		return (0);
	while (g_lex_arif && g_lex_arif->type >= PLUS && g_lex_arif->type <= MINUS)
	{
		type = g_lex_arif->type;
		g_lex_arif = g_lex_arif->next;
		right_value = expr_multiplicativ();
		if (g_error_arithmetic)
			return (0);
		if (type == PLUS)
			left_value = left_value + right_value;
		else
			left_value = left_value - right_value;
	}
	return (left_value);
}
