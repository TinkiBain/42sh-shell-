/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expr_logic_and.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwisoky <dwisoky@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/29 19:06:33 by dwisoky           #+#    #+#             */
/*   Updated: 2019/10/11 18:49:53 by dwisoky          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arifmetic.h"

long		expr_logic_and(void)
{
	long	left_value;
	long	right_value;

	left_value = expr_equal();
	if (g_error_arifmetic)
		return (0);
	while (g_lex_arif && g_lex_arif->type == LOGICAL_AND)
	{
		g_lex_arif = g_lex_arif->next;
		right_value = expr_equal();
		if (g_error_arifmetic)
			return (0);
		left_value = left_value & right_value;
	}
	return (left_value);
}
