/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expr_logic_or.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwisoky <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/29 18:39:39 by dwisoky           #+#    #+#             */
/*   Updated: 2019/10/01 17:02:03 by dwisoky          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arifmetic.h"

size_t		expr_logic_or(void)
{
	size_t	left_value;
	size_t	right_value;

	left_value = expr_exclusive_or();
	if (g_error_arifmetic)
		return (0);
	while (g_lex_arif && g_lex_arif->type == LOGICAL_OR)
	{
		g_lex_arif = g_lex_arif->next;
		right_value = expr_exclusive_or();
		if (g_error_arifmetic)
			return (0);
		left_value = left_value | right_value;
	}
	return (left_value);
}
