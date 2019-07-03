/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_and_or.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggwin-go <ggwin-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/01 09:48:32 by dwisoky           #+#    #+#             */
/*   Updated: 2019/07/03 18:19:19 by ggwin-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
// include "sh.h" for using g_errno
#include "sh.h"

t_and_or		*parser_init_and_or(void)
{
	t_and_or	*elem;

	elem = (t_and_or*)ft_xmalloc(sizeof(t_and_or));
	elem->and_or = NULL;
	elem->pipeline = NULL;
	elem->and_or_if = 0;
	return (elem);
}

t_and_or		*parser_and_or(t_lex **lex, t_and_or *elem_down, int semicolon)
{
	t_and_or	*elem;
	t_lex		**tmp;
	t_lex		**begin;
	int			type;

	(void)elem_down;
	begin = lex;
	tmp = begin;
	elem = parser_init_and_or();
	while (*lex)
	{
		if ((type = (*lex)->type) & AND_IF || type & OR_IF)
		{
			tmp = &(*lex)->next;
			free_lex(lex);
			elem->pipeline = parser_pipeline(begin);
			elem->and_or_if = type;
			elem->and_or = parser_and_or(tmp, elem, type);
			break ;
		}
		lex = &(*lex)->next;
	}
	if (!tmp && semicolon)
	{
		parser_print_error(";");
		g_errno = SEMICOLON;
	}
	elem->pipeline = parser_pipeline(begin);
	return (elem);
}
