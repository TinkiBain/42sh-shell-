/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_and_or.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggwin-go <ggwin-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/01 09:48:32 by dwisoky           #+#    #+#             */
/*   Updated: 2019/08/25 17:32:49 by dwisoky          ###   ########.fr       */
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

t_and_or		*parser_and_or_error(void)
{
	g_error_pars = 2;
	return (NULL);
}

t_and_or		*parser_and_or(t_lex *lex)
{
	t_and_or	*elem;
	t_lex		*tmp;
	t_lex		*begin;

	if (!(lex && (begin = lex)))
		return (parser_and_or_error());
	if (lex->type & AND_IF || lex->type & OR_IF)
		return (parser_print_error("&&"));
	elem = init_and_or();
	while (lex->next)
	{
		if (lex->next->type & AND_IF || lex->next->type & OR_IF)
		{
			tmp = lex->next->next;
			elem->and_or_if = lex->next->type;
			lex->next = NULL;
			if (!(elem->and_or = parser_and_or(tmp)))
				return (parser_free_and_or(elem));
			break ;
		}
		lex = lex->next;
	}
	if (!(elem->pipeline = parser_pipeline(begin)))
		return (parser_free_and_or(elem));
	return (elem);
}
