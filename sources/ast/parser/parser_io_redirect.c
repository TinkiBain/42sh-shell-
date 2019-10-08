/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_io_redirect.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggwin-go <ggwin-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 18:29:18 by dwisoky           #+#    #+#             */
/*   Updated: 2019/10/08 18:08:05 by dwisoky          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

t_io_redirect			*parser_free_io_redirect(t_io_redirect *list)
{
	if (!list)
		return (NULL);
	if (list->file_name)
		free(list->file_name);
	if (list->compound_list)
		parser_free_compound_list(list->compound_list);
	free(list);
	return (NULL);
}

static t_io_redirect	*parser_init_io_redirect(int type, int io_number)
{
	t_io_redirect		*list;

	list = (t_io_redirect*)ft_xmalloc(sizeof(t_io_redirect));
	list->file_name = NULL;
	list->io_number = io_number;
	list->type = type;
	list->compound_list = NULL;
	return (list);
}

t_io_redirect			*parser_check_subshell(int io_number)
{
	t_io_redirect		*list;

	if (g_lex->next->type == LBRACKET)
	{
		list = parser_init_io_redirect(g_lex->type, io_number);
		g_lex = g_lex->next;
		list->compound_list = parser_subshell();
		if (g_error_lex)
			return (parser_free_io_redirect(list));
		return (list);
	}
	else if (g_lex->next->type == WORD)
	{
		list = parser_init_io_redirect(g_lex->type, io_number);
		g_lex = g_lex->next;
		list->file_name = ft_strdup(g_lex->lexem);
		g_lex = g_lex->next;
		return (list);
	}
	else
	{
		g_error_lex = g_lex;
		return (NULL);
	}
}

t_io_redirect			*parser_io_redirect(void)
{
	t_io_redirect		*list;
	int					io_number;

	list = NULL;
	io_number = -1;
	if (g_lex && g_lex->type == IO_NUMBER)
		io_number = parser_io_number();
	if (g_lex && (g_lex->type == GREAT || g_lex->type == LESS))
		return (parser_check_subshell(io_number));
	if (g_lex && g_lex->type >= ANDGREAT && g_lex->type <= LESSGREAT)
	{
		list = parser_init_io_redirect(g_lex->type, io_number);
		g_lex = g_lex->next;
		if (g_lex)
		{
			if (g_lex->type == WORD)
				list->file_name = ft_strdup(g_lex->lexem);
			else
			{
				g_error_lex = g_lex;
				return (parser_free_io_redirect(list));
			}
			g_lex = g_lex->next;
		}
	}
	return (list);
}
