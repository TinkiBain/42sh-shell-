/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_print_error.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwisoky <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 17:29:16 by dwisoky           #+#    #+#             */
/*   Updated: 2019/10/12 17:29:18 by dwisoky          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

void		parser_print_error(void)
{
	if (!g_error_lex)
		return ;
	if (g_error_lex->type == ERR_SINT)
		return ;
	if (g_error_lex->type == WORD || g_error_lex->type == IO_NUMBER)
		print_error_vaarg("syntax error near unexpected token `%s'\n",
				g_error_lex->lexem);
	else if (g_error_lex->type == EOF)
		print_error("syntax error", "unexpeced end of file");
	else
		print_error_vaarg("syntax error near unexpected token `%s'\n",
				get_lexem_value(g_error_lex->type));
}
