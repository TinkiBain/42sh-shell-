/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ast_cmd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggwin-go <ggwin-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/18 22:47:54 by ggwin-go          #+#    #+#             */
/*   Updated: 2019/08/18 23:03:11 by ggwin-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "print_ast.h"

static void		print_ast_handle_pref(t_cmd_prefix *pref)
{
	while (pref)
	{
		if (pref->assignment_word)
			print_ast_token_assignment_word(pref->assignment_word);
		else
			print_ast_io_redir(pref->io_redir);
		pref = pref->cmd_pref;
	}
}

void			print_ast_cmd(t_cmd *cmd)
{
	t_cmd_suffix	*suff;
	t_cmd_prefix	*pref;

	pref = cmd->cmd_pref;
	if (pref)
	{
		print_ast_handle_pref(pref);
		if (cmd->cmd_word)
			print_ast_token_word(cmd->cmd_word);
	}
	else
		print_ast_token_word(cmd->cmd_name);
	suff = cmd->cmd_suf;
	while (suff)
	{
		if (suff->word)
			print_ast_token_word(suff->word);
		else
			print_ast_io_redir(suff->io_redir);
		suff = suff->cmd_suf;
	}
}
