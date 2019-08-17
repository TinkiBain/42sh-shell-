/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_cmd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggwin-go <ggwin-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/04 20:47:34 by ggwin-go          #+#    #+#             */
/*   Updated: 2019/08/17 06:08:45 by gmelisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "sh.h"

static t_cmd	*init_cmd(void)
{
	t_cmd		*elem;

	elem = (t_cmd*)ft_xmalloc(sizeof(t_cmd));
	elem->cmd_pref = NULL;
	elem->cmd_suf = NULL;
	elem->cmd_word = NULL;
	elem->cmd_name = NULL;
	return (elem);
}

t_cmd			*parser_cmd(t_lex *lex)
{
	t_cmd		*cmd;
	t_lex		*tmp;

	if (!lex)
		return (NULL);
	cmd = init_cmd();
	tmp = parser_cmd_prefix(lex, &cmd->cmd_pref);
	if (!tmp)
		return (cmd);
	if (lex == tmp)
		cmd->cmd_name = ft_xstrdup(tmp->lexeme);
	else
		cmd->cmd_word = ft_xstrdup(tmp->lexeme);
	tmp = tmp->next;
	parser_cmd_suffix(tmp, &cmd->cmd_suf);
	return (cmd);
}
