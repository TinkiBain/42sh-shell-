/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expr_equal.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jterry <jterry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/29 19:09:41 by dwisoky           #+#    #+#             */
/*   Updated: 2019/10/25 16:39:54 by jterry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arithmetic.h"

long		expr_equal(void)
{
	long	right_value;
	long	left_value;
	int		type;

	left_value = expr_relat_op();
	if (g_error_arithmetic)
		return (0);
	while (g_lex_arif && (g_lex_arif->type == EQUAL_IF
				|| g_lex_arif->type == NOT_EQUAL_IF))
	{
		type = g_lex_arif->type;
		g_lex_arif = g_lex_arif->next;
		right_value = expr_relat_op();
		if (g_error_arithmetic)
			return (0);
		if (type == EQUAL_IF)
			left_value = left_value == right_value;
		else
			left_value = left_value != right_value;
	}
	return (left_value);
}
