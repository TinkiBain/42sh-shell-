/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_recall_readline.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwisoky <dwisoky@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 18:35:55 by dwisoky           #+#    #+#             */
/*   Updated: 2019/10/14 01:22:26 by dwisoky          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "error.h"

char			*parser_error_recall_readline(char c)
{
	extern int	g_eof;

	if (g_error_lex->type != ERR_SINT)
		print_error_vaarg("unexpected EOF while "
							"looking for matching `%c'\n", c);
	g_eof = 0;
	return (NULL);
}

char			*parser_recall_readline(char c)
{
	extern int	g_eof;
	extern char	*g_buf;
	char		*new_str;
	t_lex		*lex;

	new_str = NULL;
	g_lex->lexem = ft_xstrrejoin(g_lex->lexem, "\n", 1);
	while (!new_str)
	{
		new_str = parser_call_back_readline(0);
		if (g_error_lex)
			return (parser_error_recall_readline(c));
	}
	g_buf = ft_xstrrejoin(g_lex->lexem, new_str, 3);
	lex = lexer(g_buf);
	lex->next = g_lex->next;
	while (lex->back)
		lex = lex->back;
	g_lex->lexem = lex->lexem;
	g_lex->next = lex->next;
	free(lex);
	return (g_lex->lexem);
}
