/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expr_get_var_value.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwisoky <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/24 20:10:31 by dwisoky           #+#    #+#             */
/*   Updated: 2019/10/02 17:06:57 by dwisoky          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arifmetic.h"

size_t			expr_get_var_value(void)
{
	char	*begin;
	char	*var;

	var = get_var_value(g_lex_arif->lexem);
	begin = var;
	if (!begin)
	{
		g_lex_arif = g_lex_arif->next;
		return (0);
	}
	while (*var == '+' || *var == '-')
		++var;
	while (*var >= '0' && *var <= '9')
		++var;
	if (!*var)
	{
		g_lex_arif = g_lex_arif->next;
		return (atoll(begin));
	}
	g_error_arifmetic = g_lex_arif;
	return (0);
}
