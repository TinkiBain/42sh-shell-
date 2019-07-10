/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_and_or.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggwin-go <ggwin-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/01 09:48:32 by dwisoky           #+#    #+#             */
/*   Updated: 2019/07/09 21:24:30 by dwisoky          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static t_and_or	*init_and_or(void)
{
	t_and_or	*elem;

	elem = (t_and_or*)ft_xmalloc(sizeof(t_and_or));
	elem->and_or = NULL;
	elem->pipeline = NULL;
	elem->and_or_if = 0;
	return (elem);
}

t_and_or		*parser_and_or(t_lex **lex)
{
	t_and_or	*elem;
	t_lex		**tmp;
	t_lex		**begin;
	int			type;

	printf("AND_OR\n");
	begin = lex;
	tmp = begin;
	elem = init_and_or();
	while (*lex)
	{
		if ((type = (*lex)->type) & AND_IF || type & OR_IF)
		{
			tmp = &(*lex)->next;
			free_lex(lex);
			elem->and_or_if = type;
			elem->and_or = parser_and_or(tmp);
			break ;
		}
		lex = &(*lex)->next;
	}
	elem->pipeline = parser_pipeline(begin);
	return (elem);
}
