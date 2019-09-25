/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expr_bracket.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwisoky <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/24 22:17:59 by dwisoky           #+#    #+#             */
/*   Updated: 2019/09/25 22:24:07 by dwisoky          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arifmetic.h"

size_t		expr_bracket(void)
{
	if (g_lex_arif && g_lex_arif->type == LBRACKET_ARIF)
	{
		g_lex_arif = g_lex_arif->next;
		return (expr());
	}
	if (g_lex_arif && g_lex_arif->type == RBRACKET_ARIF)
	{
		g_lex_arif = g_lex_arif->next;
		return (0);
	}
	return (expr_check_var());
}
