/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expr_and.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwisoky <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/29 18:34:31 by dwisoky           #+#    #+#             */
/*   Updated: 2019/10/01 17:01:03 by dwisoky          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arifmetic.h"

size_t		expr_and(void)
{
	size_t	left_value;
	size_t	right_value;

	left_value = expr_logic_or();
	if (g_error_arifmetic)
		return (0);
	while (g_lex_arif && g_lex_arif->type == AND)
	{
		g_lex_arif = g_lex_arif->next;
		right_value = expr_logic_or();
		if (g_error_arifmetic)
			return (0);
		left_value = left_value && right_value;
	}
	return (left_value);
}
