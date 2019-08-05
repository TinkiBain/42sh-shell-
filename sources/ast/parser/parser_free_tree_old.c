/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_free_tree.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwisoky <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/10 19:44:41 by dwisoky           #+#    #+#             */
/*   Updated: 2019/07/15 20:43:27 by dwisoky          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static void		parser_free_io_redir(t_io_redirect *io_redir)
{
	if (io_redir->file_name)
		free(io_redir->file_name);
	free(io_redir);
}

static void		parser_free_cmd_suffix(t_cmd_suffix *cmd_suffix)
{
	if (cmd_suffix->word)
		free(cmd_suffix->word);
	if (cmd_suffix->io_redir)
		parser_free_io_redir(cmd_suffix->io_redir);
	if (cmd_suffix->cmd_suf)
		parser_free_cmd_suffix(cmd_suffix->cmd_suf);
	free(cmd_suffix);
}

static void		parser_free_cmd_prefix(t_cmd_prefix *cmd_prefix)
{
	if (cmd_prefix->assignment_word)
		free(cmd_prefix->assignment_word);
	if (cmd_prefix->io_redir)
		parser_free_io_redir(cmd_prefix->io_redir);
	if (cmd_prefix->cmd_pref)
		parser_free_cmd_prefix(cmd_prefix->cmd_pref);
	free(cmd_prefix);
}

static void		parser_free_pipe_sequence(t_pipe_sequence *pipe_sequence)
{
	t_cmd		*cmd;

	if (!pipe_sequence)
		return ;
	if (pipe_sequence->next)
		parser_free_pipe_sequence(pipe_sequence->next);
	if (pipe_sequence->cmd)
	{
		cmd = pipe_sequence->cmd;
		if (cmd->cmd_word)
			free(cmd->cmd_word);
		if (cmd->cmd_name)
			free(cmd->cmd_name);
		if (cmd->cmd_pref)
			parser_free_cmd_prefix(cmd->cmd_pref);
		if (cmd->cmd_suf)
			parser_free_cmd_suffix(cmd->cmd_suf);
		free(cmd);
	}
	free(pipe_sequence);
}

void			parser_free_tree(t_pars_list *list)
{
	t_and_or	*tmp;

	if (!list)
		return ;
	if (list->list)
		parser_free_tree(list->list);
	while (list->and_or)
	{
		tmp = list->and_or;
		if (tmp->pipeline)
		{
			if (tmp->pipeline->pipe_sequence)
				parser_free_pipe_sequence(tmp->pipeline->pipe_sequence);
			free(tmp->pipeline);
		}
		list->and_or = tmp->and_or;
		free(tmp);
	}
	free(list);
}
