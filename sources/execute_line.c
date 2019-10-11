/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_line.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jterry <jterry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/27 19:00:12 by gmelisan          #+#    #+#             */
/*   Updated: 2019/10/11 17:23:36 by jterry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

char				*g_buf;

t_complete_cmd		*exec_ast(char *buf, t_lex **lex)
{
	t_complete_cmd	*list;
	extern char		*g_buf;

	*lex = lexer(buf);
	if (!*lex)
	{
		free(buf);
		return (NULL);
	}
	g_buf = buf;
	while ((*lex)->back)
		(*lex) = (*lex)->back;
	g_lex = *lex;
	g_error_lex = NULL;
	list = parser();
	if (g_error_lex)
	{
		parser_print_error();
		if (g_error_lex->type == EOF || g_error_lex->type == ERR_SINT)
			free(g_error_lex);
		list = parser_free(list);
	}
	free(g_buf);
	return (list);
}

void					execute_line(char *line)
{
	t_complete_cmd	*list;
	t_lex			*lex;
	char			*tmp;

	if (*(tmp = ft_xstrtrim(line)))
	{
		list = exec_ast(line, &lex);
		if (list)
			traverse_ast(list);
		parser_free(list);
		lexer_free_all(lex);
	}
	else
		ft_strdel(&line);
	ft_strdel(&tmp);
}
