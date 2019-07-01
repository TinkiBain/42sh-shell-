/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_and_or.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggwin-go <ggwin-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/01 09:48:32 by dwisoky           #+#    #+#             */
/*   Updated: 2019/07/01 17:38:32 by ggwin-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

t_and_or		*parser_init_and_or(int type)
{
	t_and_or	*elem;

	elem = (t_and_or*)ft_xmalloc(sizeof(t_and_or));
	elem->and_or = NULL;
	elem->pipeline = NULL;
	elem->and_or_if = type;
	return (elem);
}

t_and_or		*parser_and_or(t_lex **lex, t_and_or *elem_down, int type)
{
	t_and_or	*elem;
	t_lex		**tmp;
	t_lex		**begin;
	
	begin = lex;
	elem = parser_init_and_or(type);
	if (elem_down)
		elem->and_or = elem_down;
	while (*lex)
	{
		if ((*lex)->type & AND_IF || (*lex)->type & OR_IF)
		{
			type = (*lex)->type;
			tmp = &(*lex)->next;
			free_lex(lex);
			elem->pipeline = parser_pipeline(begin);
			// printf("%s\n", (*tmp)->lexeme);
			return (parser_and_or(tmp, elem, type));
		}
		lex = &(*lex)->next;
	}
	elem->pipeline = parser_pipeline(begin);
	return (elem);
}
