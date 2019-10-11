/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expr_check_var.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwisoky <dwisoky@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 22:05:45 by dwisoky           #+#    #+#             */
/*   Updated: 2019/10/11 19:21:58 by dwisoky          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arifmetic.h"

long	expr_check_var(void)
{
	if (!g_lex_arif)
	{
		init_lex(EOF_AR, NULL, &g_error_arifmetic);
		return (0);
	}
	if (g_lex_arif->type == DIGIT)
		return (expr_digit());
	if (g_lex_arif->type == VAR)
		return (expr_get_var_value());
	g_error_arifmetic = g_lex_arif;
	return (0);
}
