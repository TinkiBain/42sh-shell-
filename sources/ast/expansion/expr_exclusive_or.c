/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expr_exclusive_or.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jterry <jterry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/29 18:54:33 by dwisoky           #+#    #+#             */
/*   Updated: 2019/10/25 16:39:54 by jterry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arithmetic.h"

long		expr_exclusive_or(void)
{
	long	left_value;
	long	right_value;

	left_value = expr_logic_and();
	if (g_error_arithmetic)
		return (0);
	while (g_lex_arif && g_lex_arif->type == EXCLUSIVE_OR)
	{
		g_lex_arif = g_lex_arif->next;
		right_value = expr_logic_and();
		if (g_error_arithmetic)
			return (0);
		left_value = left_value ^ right_value;
	}
	return (left_value);
}
