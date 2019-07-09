/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_cmd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggwin-go <ggwin-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/04 20:47:34 by ggwin-go          #+#    #+#             */
/*   Updated: 2019/07/09 18:02:36 by dwisoky          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "sh.h"

static t_cmd	*init_cmd(void)
{
	t_cmd	*elem;

	elem = (t_cmd*)ft_xmalloc(sizeof(t_cmd));
	elem->cmd_pref = NULL;
	elem->cmd_suf = NULL;
	elem->cmd_word = NULL;
	elem->cmd_name = NULL;
	return (elem);
}

t_cmd	*parser_cmd(t_lex **lex)
{
	t_cmd		*cmd;
	t_lex		**tmp;

	if (!lex)
		return (NULL);
	tmp = lex;
	printf("PARSER_CMD\n");
	cmd = init_cmd();
	lex = parser_cmd_prefix(lex, &cmd->cmd_pref);
	if (*lex && *lex == *tmp)
		cmd->cmd_name = ft_strdup((*lex)->lexeme);
	else if (*lex)
		cmd->cmd_word = ft_strdup((*lex)->lexeme);
	tmp = &(*lex)->next;
	free_lex(lex);
	parser_cmd_suffix(tmp, &(cmd->cmd_suf));
	return (cmd);
}
