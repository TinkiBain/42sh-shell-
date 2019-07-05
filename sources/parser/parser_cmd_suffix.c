/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_cmd_suffix.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggwin-go <ggwin-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/05 22:18:22 by ggwin-go          #+#    #+#             */
/*   Updated: 2019/07/05 22:19:11 by ggwin-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static t_cmd_suffix	*init_cmd_suffix(void)
{
	t_cmd_suffix	*cmd_suf;

	cmd_suf = (t_cmd_suffix*)ft_xmalloc(sizeof(t_cmd_suffix));
	cmd_suf->word = NULL;
	cmd_suf->cmd_suf = NULL;
	cmd_suf->io_redir = NULL;
	return (cmd_suf);
}

t_cmd_suffix		*parser_cmd_suffix(t_lex *lex)
{
	t_cmd_suffix	*cmd_suf;

	cmd_suf = init_cmd_suffix();
	if (lex->lexeme)
		cmd_suf->word = lex->lexeme;
	cmd_suf->io_redir = parser_io_redirect(lex);
	cmd_suf->cmd_suf = NULL;
	return (cmd_suf);
}
