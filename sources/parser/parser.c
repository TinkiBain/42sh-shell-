/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwisoky <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/30 19:52:13 by dwisoky           #+#    #+#             */
/*   Updated: 2019/07/01 13:06:09 by dwisoky          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void				free_lex(t_lex **lex)
{
	if ((*lex)->lexeme)
		free((*lex)->lexeme);
	free(*lex);
	*lex = NULL;
}

t_pars_list			*init_list(void)
{
	t_pars_list		*list;

	list = (t_pars_list*)ft_xmalloc(sizeof(t_pars_list));
	list->list = NULL;
	list->and_or = NULL;
	list->sep = 0;
	return (list);
}

t_pars_list			*parser(t_lex **lex, t_pars_list *list_down)
{
	t_pars_list		*list;
	t_lex			**tmp;
	t_lex			**begin;

	list = init_list();
	begin = &(*lex);
	if (list_down)
	{
		list->list = list_down;
		list->sep = 1;
	}
	while (*lex)
	{
		if ((*lex)->type == SEMICOLON)
		{
			tmp = &(*lex)->next;
			free_lex(lex);
			list->and_or = parser_and_or(begin);
			return (parser(tmp, list));
		}
		lex = &(*lex)->next;
	}
	list->and_or = parser_and_or(begin);
	return (list);
}
