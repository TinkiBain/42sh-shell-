/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_exec.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggwin-go <ggwin-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/04 19:23:21 by ggwin-go          #+#    #+#             */
/*   Updated: 2019/07/28 15:22:19 by ggwin-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"
#include "exec.h"

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
	else if (type & ANDDGREAT)
		ft_putstr("&>>");
}

static void	print_io_redir(t_io_redirect *redir)
{
	ft_putnbr(redir->io_number);
	print_token_number(redir->type);
	ft_putstr(redir->file_name);
	write(1, " ", 1);
}

static void	print_cmd(t_cmd *cmd)
{
	t_cmd_suffix	*suff;
	t_cmd_prefix	*pref;

	pref = cmd->cmd_pref;
	if (pref)
	{
		while (pref)
		{
			if (pref->assignment_word)
				print_token_word(pref->assignment_word);
			else
				print_io_redir(pref->io_redir);
			pref = pref->cmd_pref;
		}
		print_token_word(cmd->cmd_av);
	}
	else
		print_token_word(cmd->cmd_name);
	suff = cmd->cmd_suf;
	while (suff)
	{
		if (suff->word)
			print_token_word(suff->word);
		else
			print_io_redir(suff->io_redir);
		suff = suff->cmd_suf;
	}
}

static void	pipe_sequence_iter(t_pipe_sequence *pipe_seq)
{
	extern char	**environ;

	if (pipe_seq)
	{
		if (pipe_seq->pipe_op)
			pipe_sequence_iter(pipe_seq->next);
		print_cmd(pipe_seq->cmd);

	}
}

static void	pipeline_iter(t_pipeline *root)
{
	pipe_sequence_iter(root->pipe_sequence);
	if (root->bang)
		g_res_exec = ~g_res_exec;
}

static void	and_or_iter_in_order(t_and_or *root)
{
	g_res_exec = 0;
	pipeline_iter(root->pipeline);
	if (root->and_or)
	{
		if ((root->and_or_if == AND_IF && !g_res_exec) || (root->and_or_if == OR_IF && g_res_exec))
			and_or_iter_in_order(root->and_or);
	}
}

void		ast_print_in_order(t_pars_list *root)
{
	if (!root)
		return ;
	if (root->list)
	{
		ast_print_in_order(root->list);
	}
	if (root->and_or)
		and_or_iter_in_order(root->and_or);
}
