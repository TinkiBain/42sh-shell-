/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_free_cmd.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggwin-go <ggwin-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/26 17:44:42 by dwisoky           #+#    #+#             */
/*   Updated: 2019/07/28 21:50:45 by ggwin-go         ###   ########.fr       */
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

static void		parser_free_cmd_av(t_vector *vec)
{
	ft_strarrdel((char ***)&vec->v);
	free(vec);
}

void			*parser_free_cmd(t_cmd *cmd)
{
	if (!cmd)
		return (NULL);
	if (cmd->cmd_av)
		parser_free_cmd_av(cmd->cmd_av);
	cmd->cmd_av = NULL;
	if (cmd->cmd_name)
		free(cmd->cmd_name);
	cmd->cmd_name = NULL;
	if (cmd->cmd_pref)
		parser_free_cmd_prefix(cmd->cmd_pref);
	cmd->cmd_pref = NULL;
	if (cmd->cmd_suf)
		parser_free_cmd_suffix(cmd->cmd_suf);
	cmd->cmd_suf = NULL;
	free(cmd);
	cmd = NULL;
	return (NULL);
}
