/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expr_and.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwisoky <dwisoky@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/29 18:34:31 by dwisoky           #+#    #+#             */
/*   Updated: 2019/10/11 18:48:41 by dwisoky          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arifmetic.h"

long		expr_and(void)
{
	long	left_value;
	long	right_value;

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
