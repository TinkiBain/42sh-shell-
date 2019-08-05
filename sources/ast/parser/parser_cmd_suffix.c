/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_cmd_suffix.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggwin-go <ggwin-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/05 22:18:22 by ggwin-go          #+#    #+#             */
/*   Updated: 2019/07/15 19:46:53 by dwisoky          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static t_cmd_suffix	*init_cmd_suffix(t_lex *lex)
{
	t_cmd_suffix	*cmd_suf;

	cmd_suf = (t_cmd_suffix*)ft_xmalloc(sizeof(t_cmd_suffix));
	if (lex->type & WORD)
	{
		cmd_suf->word = ft_strdup(lex->lexeme);
		cmd_suf->io_redir = NULL;
	}
	else
	{
		cmd_suf->word = NULL;
		cmd_suf->io_redir = parser_io_redirect(lex);
	}
	cmd_suf->cmd_suf = NULL;
	return (cmd_suf);
}

void				parser_cmd_suffix(t_lex *lex, t_cmd_suffix **cmd_suffix)
{
	t_lex			*tmp;

	while (lex)
	{
		tmp = lex;
		*cmd_suffix = init_cmd_suffix(lex);
		cmd_suffix = &(*cmd_suffix)->cmd_suf;
		lex = lex->next;
	}
}
