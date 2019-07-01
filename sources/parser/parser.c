/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwisoky <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/30 19:52:13 by dwisoky           #+#    #+#             */
/*   Updated: 2019/07/01 15:42:59 by dwisoky          ###   ########.fr       */
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

t_pars_list			*init_pars_list(void)
{
	t_pars_list		*list_pars;

	list_pars = (t_pars_list*)ft_xmalloc(sizeof(t_pars_list));
	list_pars->list = NULL;
	list_pars->and_or = NULL;
	list_pars->sep = 0;
	return (list_pars);
}

t_pars_list			*parser(t_lex **lex, t_pars_list *list_down)
{
	t_pars_list		*list_pars;
	t_lex			**tmp;
	t_lex			**begin;

	if ((*lex)->type & SEMICOLON)
	{
		parser_print_error(";;");
		return (NULL);
	}
	list_pars = init_pars_list();
	if (list_down)
		list_pars->list = list_down;
	begin = lex;
	while (*lex)
	{
		if ((*lex)->type & SEMICOLON)
		{
			list_pars->sep = 1;
			tmp = &(*lex)->next;
			free_lex(lex);
			parser_and_or(begin, NULL);
			return (parser(tmp, list_pars));
		}
		lex = &(*lex)->next;
	}
	return (list_pars);
}
