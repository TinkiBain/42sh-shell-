/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_brace_group.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwisoky <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 17:58:28 by dwisoky           #+#    #+#             */
/*   Updated: 2019/09/09 18:44:47 by dwisoky          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Grammar rule
** brace_group      : Lbrace compound_list Rbrace
**                  ;
*/

#include "parser.h"

t_compound_list		*parser_brace_group(void)
{
	t_compound_list	*tmp;

	g_lex = g_lex->next;
	tmp = parser_compound_list();
	if (g_lex->type == WORD && ft_strequ(g_lex->lexem, "}"))
		g_lex = g_lex->next;
	else
		g_error_lex = g_lex;
	return (tmp);
}
