/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_redirect_list.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwisoky <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 19:47:51 by dwisoky           #+#    #+#             */
/*   Updated: 2019/09/07 20:04:50 by dwisoky          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

/*
** Grammar rule
** redirect_list    :               io_redirect
**                  | redirect_list io_redirect
**                  ;
*/

t_redirect_list			*parser_free_redirect_list(t_redirect_list *list)
{
	if (!list)
		return (NULL);
	parser_free_io_redirect(list->io_redirect);
	parser_free_redirect_list(list->next);
	free(list);
	return (NULL);
}

static t_redirect_list	*parser_init_redirect_list(t_redirect_list *list_down)
{
	t_redirect_list		*list;

	list = (t_redirect_list*)ft_xmalloc(sizeof(t_redirect_list));
	list->next = list_down;
	list->io_redirect = NULL;
	return (list);
}

t_redirect_list			*parser_redirect_list(t_redirect_list *list_down)
{
	t_redirect_list	*list;

	if (!g_lex)
		return (NULL);
	list = parser_init_redirect_list(list_down);
	list->io_redirect = parser_io_redirect();
	if (!list)
		return (parser_free_redirect_list(list));
	return (parser_redirect_list(list));
}
