/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_do_group.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwisoky <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 20:20:23 by dwisoky           #+#    #+#             */
/*   Updated: 2019/09/10 20:38:01 by dwisoky          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

/*
** Grammar rule
** do_group         : Do compound_list Done            Apply rule 6
**                  ;
*/

t_compound_list		*parser_do_group(void)
{
	t_compound_list	*list;

	if (!(g_lex->type == WORD && ft_strequ(g_lex->lexem, "do")))
	{
		g_error_lex = g_lex;
		return (NULL);
	}
	g_lex = g_lex->next;
	list = parser_compound_list();
	if (g_error_lex)
		return (parser_free_compound_list(list));
	if (!(g_lex->type == WORD && ft_strequ(g_lex->lexem, "done")))
	{
		g_error_lex = g_lex;
		return (parser_free_compound_list(list));
	}
	g_lex = g_lex->next;
	return (list);
}
