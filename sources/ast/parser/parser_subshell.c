/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_subshell.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwisoky <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 17:52:20 by dwisoky           #+#    #+#             */
/*   Updated: 2019/09/08 17:38:22 by dwisoky          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

/*
** Grammar rule
** subshell         : '(' compound_list ')'
**					;
*/

t_compound_list		*parser_subshell(void)
{
	t_compound_list	*tmp;

	g_lex = g_lex->next;
	tmp = parser_compound_list();
	if (!g_lex)
		return (tmp); // убрать после вызова readline
	if (g_lex->type == RBRACKET)
		g_lex = g_lex->next;
	else
		g_error_lex = g_lex;
	return (tmp);
}
