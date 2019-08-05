/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_pipe_sequence.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggwin-go <ggwin-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/04 20:31:43 by ggwin-go          #+#    #+#             */
/*   Updated: 2019/08/02 19:49:18 by dwisoky          ###   ########.fr       */
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

void					*parser_pipe_sequence_check_error(int type)
{
	if (type & PIPE_SYMB)
		return (parser_print_error("|"));
	if (type & BANG)
		return (parser_print_error("!"));
	return ((void*)1);
}

t_pipe_sequence			*parser_pipe_sequence(t_lex *lex)
{
	t_pipe_sequence		*pipe_seq;
	t_lex				*begin;
	t_lex				*tmp;

	begin = lex;
	if (!parser_pipe_sequence_check_error(lex->type))
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
			if (!pipe_seq->next)
				return (parser_free_pipe_sequence(pipe_seq));
			break ;
		}
		lex = lex->next;
	}
	if (!(pipe_seq->cmd = parser_cmd(begin)))
		return (parser_free_pipe_sequence(pipe_seq));
	return (pipe_seq);
}
