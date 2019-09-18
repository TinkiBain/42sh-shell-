/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_recall_readline.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwisoky <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 18:35:55 by dwisoky           #+#    #+#             */
/*   Updated: 2019/09/18 15:38:28 by dwisoky          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

char	 *parser_recall_readline(char *begin)
{
	extern char	*g_buf;
	char		*new_str;
	t_lex		*lex;
	int			i;

	begin = NULL;
	new_str = NULL;
	g_lex->lexem = ft_strrejoin(g_lex->lexem, "\n", 1);
	i = ft_strlen(g_lex->lexem);
	while (!new_str)
		new_str = parser_call_back_readline();
	g_buf = ft_strrejoin(g_lex->lexem, new_str, 3);
	lex = lexer(g_buf);
	lex->next = g_lex->next;
	while (lex->back)
		lex = lex->back;
	g_lex->lexem = lex->lexem;
	g_lex->next = lex->next;
	free(lex);
	return (g_lex->lexem + i);
}
