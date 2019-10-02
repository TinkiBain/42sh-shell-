/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expr_prefix.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwisoky <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/24 19:43:11 by dwisoky           #+#    #+#             */
/*   Updated: 2019/10/01 19:17:08 by dwisoky          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arifmetic.h"

size_t		expr_prefix(void)
{
	extern char	**g_var;
	size_t		var_value;
	char		*var;
	int			type;
	
	if (g_lex_arif && (g_lex_arif->type == PREFIX_ADD
				|| g_lex_arif->type == PREFIX_MIN))
	{
		type = g_lex_arif->type;
		g_lex_arif = g_lex_arif->next;
		var = ft_strjoin(g_lex_arif->lexem, "=");
		var_value = expr_get_var_value();
		if (g_error_arifmetic)
		{
			free(var);
			return (0);
		}
		if (type == PREFIX_ADD)
			++var_value;
		else
			--var_value;
		var = ft_strrejoin(var, ft_itoa_base(var_value, 10), 3);
		set_var(var, &g_var, 0);
		free(var);
		return (var_value);
	}
	return (expr_unar());
}
