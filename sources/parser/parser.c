/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggwin-go <ggwin-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/30 19:52:13 by dwisoky           #+#    #+#             */
/*   Updated: 2019/07/15 18:44:36 by dwisoky          ###   ########.fr       */
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

t_pars_list			*parser(t_lex *lex, t_pars_list *list_down, int type)
{
	t_pars_list		*list_pars;
	t_lex			*begin;
	t_lex			*tmp;

	if (!lex)
		return (list_down);
	begin = lex;
	if (lex->type & SEMICOLON)
		return (NULL);
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
			return (parser(tmp, list_pars, 1));
		}
		lex = lex->next;
	}
	list_pars->and_or = parser_and_or(begin);
	return (list_pars);
}
