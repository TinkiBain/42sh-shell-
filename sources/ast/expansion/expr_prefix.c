/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expr_prefix.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwisoky <dwisoky@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/24 19:43:11 by dwisoky           #+#    #+#             */
/*   Updated: 2019/11/02 01:28:42 by dwisoky          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arithmetic.h"

long		expr_prefix(void)
{
	extern char	**g_var;
	long		var_value;
	char		*var;
	int			type;

	if (g_lex_arif && (g_lex_arif->type == PREFIX_ADD
				|| g_lex_arif->type == PREFIX_MIN))
	{
		type = g_lex_arif->type;
		g_lex_arif = g_lex_arif->next;
		var = ft_xstrjoin(g_lex_arif->lexem, "=");
		var_value = expr_get_var_value();
		if (g_error_arithmetic)
		{
			free(var);
			return (0);
		}
		var_value += (type == PREFIX_ADD) ? 1 : -1;
		var = ft_xstrrejoin(var, ft_itoa_base(var_value, 10), 3);
		set_var(var, &g_var, 0);
		free(var);
		return (var_value);
	}
	return (expr_unar());
}
