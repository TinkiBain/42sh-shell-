/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_iter_in_order.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggwin-go <ggwin-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/04 19:23:21 by ggwin-go          #+#    #+#             */
/*   Updated: 2019/07/04 22:57:37 by ggwin-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

static void	print_token_word(char *word)
{
	ft_putstr("\'");
	ft_putstr(word);
	ft_putstr("\'");
}

static void	print_token_number(int type)
{
	if (type & SEMICOLON)
		ft_putstr(";");
	else if (type & PIPE_SYMB)
		ft_putstr("|");
	else if (type & AND_IF)
		ft_putstr("&&");
	else if (type & OR_IF)
		ft_putstr("||");
	else if (type & GREAT)
		ft_putstr(">");
	else if (type & DGREAT)
		ft_putstr(">>");
	else if (type & GREATAND)
		ft_putstr(">&");
	else if (type & LESS)
		ft_putstr("<");
	else if (type & DLESS)
		ft_putstr("<<");
	else if (type & TLESS)
		ft_putstr("<<<");
	else if (type & DLESSDASH)
		ft_putstr("<<-");
	else if (type & LESS)
		ft_putstr("<");
	else if (type & LESSAND)
		ft_putstr("<&");
	else if (type & LESSGREAT)
		ft_putstr("<>");
	else if (type & ANDGREAT)
		ft_putstr("&>");
	else if (type & ANDGREAT)
		ft_putstr("&>>");
}

static void	pipe_sequence_iter(t_pipe_sequence *pipe_seq)
{
	if (pipe_seq)
	{
		print_token_word(pipe_seq->cmd->cmd_word);
		if (pipe_seq->pipe_op)
		{
			print_token_number(PIPE_SYMB);
			pipe_sequence_iter(pipe_seq->next);
		}
	}
}

static void	pipeline_iter(t_pipeline *root)
{
	if (root->bang)
		ft_putstr("!");
	pipe_sequence_iter(root->pipe_sequence);
}

static void	and_or_iter_in_order(t_and_or *root)
{
	pipeline_iter(root->pipeline);
	if (root->and_or)
	{
		if (root->and_or_if == AND_IF || root->and_or_if == OR_IF)
			print_token_number(root->and_or_if);
		ft_putstr("\n");
		and_or_iter_in_order(root->and_or);
	}
}

void		ast_iter_in_order(t_pars_list *root)
{
	if (!root)
		return ;
	if (root->list)
	{
		ast_iter_in_order(root->list);
		if (root->sep)
			print_token_number(SEMICOLON);
		ft_putstr("\n");
	}
	if (root->and_or)
		and_or_iter_in_order(root->and_or);
}
