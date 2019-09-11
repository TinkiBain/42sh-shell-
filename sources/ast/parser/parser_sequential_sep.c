/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_sequential_sep.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwisoky <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 22:19:30 by dwisoky           #+#    #+#             */
/*   Updated: 2019/09/10 22:22:42 by dwisoky          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

/*
** Grammar rule
** sequential_sep   : ';' linebreak
**                  | newline_list
** 	                ;
*/

int			parser_sequential_sep(void)
{
	if (g_lex->type == SEMI)
	{
		g_lex = g_lex->next;
		parser_linebreak();
	}
	else
		parser_new_line_list();
	return (SEMI);
}
