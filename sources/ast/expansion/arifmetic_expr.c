/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arifmetic_expr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwisoky <dwisoky@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/24 16:34:43 by dwisoky           #+#    #+#             */
/*   Updated: 2019/10/14 01:22:05 by dwisoky          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arifmetic.h"

long		expr(void)
{
	extern char	**g_var;
	long		value;
	int			type_assign;
	char		*var;

	if (g_lex_arif->type == VAR && g_lex_arif->next &&
			g_lex_arif->next->type >= ASSIGNMENT &&
			g_lex_arif->next->type <= OR_ASSIGNMENT)
	{
		var = g_lex_arif->lexem;
		type_assign = g_lex_arif->next->type;
		g_lex_arif = g_lex_arif->next->next;
		value = expr();
		if (g_error_arifmetic)
			return (0);
		var = ft_xstrjoin(var, "=");
		var = ft_xstrrejoin(var, ft_itoa_base(value, 10), 3);
		set_var(var, &g_var, 0);
		free(var);
		return (value);
	}
	return (expr_logical_op());
}
