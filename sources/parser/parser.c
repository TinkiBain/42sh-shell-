/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggwin-go <ggwin-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/30 19:52:13 by dwisoky           #+#    #+#             */
/*   Updated: 2019/07/04 17:22:51 by dwisoky          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

void				free_lex(t_lex **lex)
{
	if ((*lex)->lexeme)
	{
		free((*lex)->lexeme);
		(*lex)->lexeme = NULL;
	}
	free(*lex);
	*lex = NULL;
}

t_pars_list			*init_pars_list(int type)
{
	t_pars_list		*list_pars;

	list_pars = (t_pars_list*)ft_xmalloc(sizeof(t_pars_list));
	list_pars->list = NULL;
	list_pars->and_or = NULL;
	list_pars->sep = type;
	return (list_pars);
}

t_pars_list			*parser(t_lex **lex, t_pars_list *list_down, int type)
{
	t_pars_list		*list_pars;
	t_lex			**tmp;
	t_lex			**begin;

	if (!*lex)
		return (list_down);
	if ((*lex)->type & SEMICOLON)
	{
		parser_print_error(";;");
		return (NULL);
	}
	list_pars = init_pars_list(type);
	if (list_down)
		list_pars->list = list_down;
	begin = lex;
	while (*lex)
	{
		if ((*lex)->type & SEMICOLON)
		{
			tmp = &(*lex)->next;
			free_lex(lex);
			list_pars->and_or = parser_and_or(begin);
			return (parser(tmp, list_pars, 1));
		}
		lex = &(*lex)->next;
	}
	list_pars->and_or = parser_and_or(begin);
	return (list_pars);
}
