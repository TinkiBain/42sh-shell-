/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expr_return_value.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwisoky <dwisoky@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 17:30:17 by dwisoky           #+#    #+#             */
/*   Updated: 2019/11/02 01:28:46 by dwisoky          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arithmetic.h"

long		expr_return_value(void)
{
	long	return_value;

	if (!g_lex_arif || (g_lex_arif->type != DIGIT && g_lex_arif->type != VAR))
	{
		init_lex(EOF_AR, NULL, &g_error_arithmetic);
		return (0);
	}
	return_value = 0;
	if (g_lex_arif->type == DIGIT)
		return_value = expr_digit();
	else
		return_value = expr_get_var_value();
	return (return_value);
}
