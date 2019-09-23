/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_case_list.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggwin-go <ggwin-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 19:16:17 by dwisoky           #+#    #+#             */
/*   Updated: 2019/09/23 14:18:24 by ggwin-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

/*
** Grammar rule
** case_list        : case_list case_item
**                  |           case_item
** 	                ;
** for the last case element, you can apply
** case_list_ns     : case_list case_item_ns
**                  |           case_item_ns
**                  ;
*/

t_case_list			*parser_free_case_list(t_case_list *list)
{
	if (!list)
		return (NULL);
	parser_free_case_list(list->next);
	parser_free_case_item(list->case_item);
	free(list);
	return (NULL);
}

static t_case_list	*parser_init_case_list(void)
{
	t_case_list		*list;

	list = (t_case_list*)ft_xmalloc(sizeof(t_case_list));
	list->next = NULL;
	list->case_item = NULL;
	return (list);
}

t_case_list			*parser_case_list(void)
{
	t_case_list		*list;

	if (g_parser_case_list_end)
		return (NULL);
	g_parser_case_list_end = 0;
	list = parser_init_case_list();
	list->case_item = parser_case_item();
	if (list->case_item && !(g_lex->type == WORD &&
					ft_strequ(g_lex->lexem, "esac")))
		list->next = parser_case_list();
	return (list);
}
