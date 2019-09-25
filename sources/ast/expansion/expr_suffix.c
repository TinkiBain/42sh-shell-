/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expr_suffix.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwisoky <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/24 21:02:27 by dwisoky           #+#    #+#             */
/*   Updated: 2019/09/25 22:10:43 by dwisoky          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arifmetic.h"

size_t		expr_suffix(void)
{
	extern char	**g_var;
	size_t		var_value;
	char		*var;
	int			type;

	if (g_lex_arif && g_lex_arif->next && g_lex_arif->type == VAR &&
			(g_lex_arif->next->type == SUFFIX_ADD
			 || g_lex_arif->next->type == SUFFIX_MIN))
	{
		var = ft_strjoin(g_lex_arif->lexem, "=");
		var_value = expr_get_var_value();
		if (g_error_arifmetic)
		{
			free(var);
			return (0);
		}
		type = g_lex_arif->type;
		g_lex_arif = g_lex_arif->next;
		if (type == SUFFIX_MIN)
			var_value -= 1;
		else
			var_value += 1;
		var = ft_strrejoin(var, ft_itoa_base(var_value, 10), 3);
		set_var(var, &g_var, 0);
		free(var);
		return (type == SUFFIX_MIN ? var_value + 1 : var_value - 1);
	}
	return (expr_check_var());
}
