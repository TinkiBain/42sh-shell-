/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expr_equal.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwisoky <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/29 19:09:41 by dwisoky           #+#    #+#             */
/*   Updated: 2019/10/01 17:44:03 by dwisoky          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arifmetic.h"

size_t		expr_equal(void)
{
	size_t	right_value;
	size_t	left_value;
	int		type;

	left_value = expr_relat_op();
	if (g_error_arifmetic)
		return (0);
	while (g_lex_arif && (g_lex_arif->type == EQUAL_IF
				|| g_lex_arif->type == NOT_EQUAL_IF))
	{
		type = g_lex_arif->type;
		g_lex_arif = g_lex_arif->next;
		right_value = expr_relat_op();
		if (g_error_arifmetic)
			return (0);
		if (type == EQUAL_IF)
			left_value = left_value == right_value;
		else
			left_value = left_value != right_value;
	}
	return (left_value);
}
