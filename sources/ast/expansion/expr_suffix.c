/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expr_suffix.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jterry <jterry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/24 21:02:27 by dwisoky           #+#    #+#             */
/*   Updated: 2019/10/25 16:39:54 by jterry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arithmetic.h"

long		expr_suffix(void)
{
	extern char	**g_var;
	long		var_value;
	char		*var;
	int			type;

	if (g_lex_arif && g_lex_arif->next && g_lex_arif->type == VAR &&
			(g_lex_arif->next->type == SUFFIX_ADD
			|| g_lex_arif->next->type == SUFFIX_MIN))
	{
		var = ft_xstrjoin(g_lex_arif->lexem, "=");
		var_value = expr_return_value();
		if (g_error_arithmetic)
		{
			free(var);
			return (0);
		}
		type = g_lex_arif->type;
		g_lex_arif = g_lex_arif->next;
		var_value += (type == SUFFIX_MIN) ? -1 : 1;
		var = ft_xstrrejoin(var, ft_itoa_base(var_value, 10), 3);
		set_var(var, &g_var, 0);
		free(var);
		return (type == SUFFIX_MIN ? var_value + 1 : var_value - 1);
	}
	return (expr_bracket());
}
