/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_compound_list.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwisoky <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 18:11:42 by dwisoky           #+#    #+#             */
/*   Updated: 2019/09/08 16:52:50 by dwisoky          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

/*
** Grammar rule
** compound_list    :              term
**                  | newline_list term
** 				    |              term separator
**                  | newline_list term separator
**	                ;
*/

t_compound_list				*parser_free_compound_list(t_compound_list *list)
{
	if (!list)
		return (NULL);
	parser_free_term(list->term);
	free(list);
	return (NULL);
}

static t_compound_list		*parser_init_compound_list(void)
{
	t_compound_list			*list;

	list = (t_compound_list*)ft_xmalloc(sizeof(t_compound_list));
	list->term = NULL;
	list->separator = 0;
	return (list);
}

t_compound_list				*parser_compound_list(void)
{
	t_compound_list	*list;

	list = parser_init_compound_list();
	parser_new_line_list();
	list->term = parser_term(NULL);
	if (g_error_lex)
		return (parser_free_compound_list(list));
	list->separator = parser_separator();
	return (list);
}
