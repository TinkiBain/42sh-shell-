/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_and_or.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwisoky <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/01 09:48:32 by dwisoky           #+#    #+#             */
/*   Updated: 2019/07/01 15:58:26 by dwisoky          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

t_and_or		*parser_init_and_or(void)
{
	t_and_or	*elem;

	elem = (t_and_or*)ft_xmalloc(sizeof(t_and_or));
	elem->and_or = NULL;
	elem->pipeline = NULL;
	elem->and_or_if = 0;
	return (elem);
}

t_and_or		*parser_and_or(t_lex **lex, t_and_or *elem_down)
{
	t_and_or	*elem;
	t_lex		**tmp;
	t_lex		**begin;
	
	begin = lex;
	elem = parser_init_and_or();
	if (elem_down)
		elem->and_or = elem_down;
	while (*lex)
	{
		if ((*lex)->type & AND_IF || (*lex)->type & OR_IF)
		{
			elem->and_or_if = (*lex)->type;
			tmp = &(*lex)->next;
			free_lex(lex);
			elem->pipeline = parser_pipeline(begin);
			return (parser_and_or(tmp, elem));
		}
		lex = &(*lex)->next;
	}
	return (elem);
}
