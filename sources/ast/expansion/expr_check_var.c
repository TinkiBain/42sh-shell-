/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expr_check_var.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jterry <jterry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 22:05:45 by dwisoky           #+#    #+#             */
/*   Updated: 2019/10/25 16:39:54 by jterry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arithmetic.h"

long	expr_check_var(void)
{
	if (!g_lex_arif)
	{
		init_lex(EOF_AR, NULL, &g_error_arithmetic);
		return (0);
	}
	if (g_lex_arif->type == DIGIT)
		return (expr_digit());
	if (g_lex_arif->type == VAR)
		return (expr_get_var_value());
	g_error_arithmetic = g_lex_arif;
	return (0);
}
