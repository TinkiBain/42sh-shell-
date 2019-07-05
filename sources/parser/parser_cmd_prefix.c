/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_cmd_prefix.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggwin-go <ggwin-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/05 20:34:31 by ggwin-go          #+#    #+#             */
/*   Updated: 2019/07/05 22:23:15 by ggwin-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static t_cmd_prefix	*init_cmd_prefix(void)
{
	t_cmd_prefix	*cmd_pref;

	cmd_pref = (t_cmd_prefix*)ft_xmalloc(sizeof(t_cmd_prefix));
	cmd_pref->assignment_word = NULL;
	cmd_pref->cmd_pref = NULL;
	cmd_pref->io_redir = NULL;
	return (cmd_pref);
}

t_cmd_prefix		*parser_cmd_prefix(t_lex *lex)
{
	t_cmd_prefix	*cmd_pref;

	cmd_pref = init_cmd_prefix();
	if (lex->lexeme)
		cmd_pref->assignment_word = lex->lexeme;
	cmd_pref->io_redir = parser_io_redirect(lex);
	cmd_pref->cmd_pref = NULL;
	return (cmd_pref);
}
