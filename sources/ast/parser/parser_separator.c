/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_separator.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwisoky <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 19:17:26 by dwisoky           #+#    #+#             */
/*   Updated: 2019/09/09 17:27:09 by dwisoky          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

/*
** Grammar rule
** separator        : separator_op linebreak
**                  | newline_list
**                  ;
*/

int		parser_separator(void)
{
	int	separator;

	separator = 0;
	if (!g_lex)
		return (0);
	if (g_lex->type == NEWLINE)
	{
		separator = SEMI;
		parser_new_line_list();
	}
	else if (g_lex->type == JOB || g_lex->type == SEMI)
	{
		separator = g_lex->type;
		g_lex = g_lex->next;
		parser_linebreak();
	}
	return (separator);
}
