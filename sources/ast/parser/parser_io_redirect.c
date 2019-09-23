/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_io_redirect.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggwin-go <ggwin-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 18:29:18 by dwisoky           #+#    #+#             */
/*   Updated: 2019/09/23 14:11:49 by ggwin-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

t_io_redirect			*parser_free_io_redirect(t_io_redirect *list)
{
	if (!list)
		return (NULL);
	if (list->file_name)
		free(list->file_name);
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
	return (list);
}

t_io_redirect			*parser_io_redirect(void)
{
	t_io_redirect		*list;
	int					io_number;

	if (!g_lex)
		return (NULL);
	list = NULL;
	io_number = -1;
	if (g_lex->type == IO_NUMBER)
		io_number = parser_io_number();
	if (g_lex->type >= ANDGREAT && g_lex->type <= LESSGREAT)
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
