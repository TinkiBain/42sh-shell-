/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_pipe_sequence.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggwin-go <ggwin-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/04 20:31:43 by ggwin-go          #+#    #+#             */
/*   Updated: 2019/07/15 18:38:42 by dwisoky          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static t_pipe_sequence	*init_pipe_sequence(void)
{
	t_pipe_sequence		*pipe_seq;

	pipe_seq = (t_pipe_sequence*)ft_xmalloc(sizeof(t_pipe_sequence));
	pipe_seq->cmd = NULL;
	pipe_seq->next = NULL;
	pipe_seq->pipe_op = 0;
	return (pipe_seq);
}

t_pipe_sequence			*parser_pipe_sequence(t_lex *lex)
{
	t_pipe_sequence		*pipe_seq;
	t_lex				*begin;
	t_lex				*tmp;

	begin = lex;
	if (lex->type & PIPE_SYMB)
		return (NULL);
	pipe_seq = init_pipe_sequence();
	while (lex->next)
	{
		if (lex->next->type & PIPE_SYMB)
		{
			tmp = lex->next->next;
			lex->next = NULL;
			pipe_seq->pipe_op = 1;
			pipe_seq->next = parser_pipe_sequence(tmp);
			break ;
		}
		lex = lex->next;
	}
	pipe_seq->cmd = parser_cmd(begin);
	return (pipe_seq);
}
