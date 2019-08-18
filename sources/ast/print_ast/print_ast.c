/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ast.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggwin-go <ggwin-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/18 23:01:30 by ggwin-go          #+#    #+#             */
/*   Updated: 2019/08/18 23:01:32 by ggwin-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"
#include "print_ast.h"

static void	print_ast_pipe_sequence(t_pipe_sequence *pipe_seq)
{
	if (pipe_seq)
	{
		print_ast_cmd(pipe_seq->cmd);
		if (pipe_seq->pipe_op)
		{
			print_ast_token_number(PIPE_SYMB);
			print_ast_pipe_sequence(pipe_seq->next);
		}
	}
}

static void	print_ast_pipeline(t_pipeline *root)
{
	if (root->bang)
		ft_putstr("!");
	print_ast_pipe_sequence(root->pipe_sequence);
}

static void	print_ast_and_or(t_and_or *root)
{
	print_ast_pipeline(root->pipeline);
	if (root->and_or)
	{
		if (root->and_or_if == AND_IF || root->and_or_if == OR_IF)
			print_ast_token_number(root->and_or_if);
		print_ast_and_or(root->and_or);
	}
}

void		print_ast(t_pars_list *root)
{
	if (!root)
		return ;
	if (root->list)
	{
		print_ast(root->list);
		if (root->sep)
			print_ast_token_number(SEMICOLON);
		ft_putstr("\n");
	}
	if (root->and_or)
		print_ast_and_or(root->and_or);
}
