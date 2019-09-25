/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expr_unar_op.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwisoky <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/24 20:52:26 by dwisoky           #+#    #+#             */
/*   Updated: 2019/09/25 20:23:29 by dwisoky          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arifmetic.h"

size_t		expr_unar_op(void)
{
	if (g_lex_arif && (g_lex_arif->type == PLUS || g_lex_arif->type == MINUS))
	{
		if (g_lex_arif->type == MINUS)
		{
			g_lex_arif = g_lex_arif->next;
			return (expr_logical_op() * -1);
		}
		else
		{
			g_lex_arif = g_lex_arif->next;
			return (expr_logical_op());
		}
	}
	return (expr_suffix());
}
