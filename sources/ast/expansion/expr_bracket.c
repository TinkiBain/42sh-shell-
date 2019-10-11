/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expr_bracket.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwisoky <dwisoky@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 20:01:02 by dwisoky           #+#    #+#             */
/*   Updated: 2019/10/11 19:21:47 by dwisoky          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arifmetic.h"

long		expr_bracket(void)
{
	long	return_value;

	if (g_lex_arif && g_lex_arif->type == LBRACKET_ARIF)
	{
		g_lex_arif = g_lex_arif->next;
		return_value = expr();
		if (g_error_arifmetic)
			return (0);
		if (g_lex_arif->type != RBRACKET_ARIF)
		{
			g_error_lex = g_lex_arif;
			return (0);
		}
		g_lex_arif = g_lex_arif->next;
		return (return_value);
	}
	return (expr_return_value());
}
