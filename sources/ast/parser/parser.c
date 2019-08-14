/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggwin-go <ggwin-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/30 19:52:13 by dwisoky           #+#    #+#             */
/*   Updated: 2019/07/26 21:04:58 by dwisoky          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

t_pars_list			*init_pars_list(int type)
{
	t_pars_list		*list_pars;

	list_pars = (t_pars_list*)ft_xmalloc(sizeof(t_pars_list));
	list_pars->list = NULL;
	list_pars->and_or = NULL;
	list_pars->sep = type;
	return (list_pars);
}

static t_pars_list	*parser_check_list(t_pars_list *value, t_pars_list *list)
{
	if (!value)
		return (parser_free_tree(list));
	return (value);
}

t_pars_list			*parser(t_lex *lex, t_pars_list *list_down, int type)
{
	t_pars_list		*list_pars;
	t_lex			*begin;
	t_lex			*tmp;

	if (!lex)
		return (list_down);
	begin = lex;
	if (lex->type & SEMICOLON)
		return (parser_print_error(";;"));
	list_pars = init_pars_list(type);
	if (list_down)
		list_pars->list = list_down;
	while (lex->next)
	{
		if (lex->next->type & SEMICOLON)
		{
			tmp = lex->next->next;
			lex->next = NULL;
			list_pars->and_or = parser_and_or(begin);
			return (parser_check_list(parser(tmp, list_pars, 1), list_pars));
		}
		lex = lex->next;
	}
	if (!(list_pars->and_or = parser_and_or(begin)))
		return (parser_free_tree(list_pars));
	return (list_pars);
}
