/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_cmd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggwin-go <ggwin-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/04 20:47:34 by ggwin-go          #+#    #+#             */
/*   Updated: 2019/07/04 22:29:38 by ggwin-go         ###   ########.fr       */
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
	t_lex		**begin;
	int			type;


	begin = lex;
	tmp = begin;
	cmd = init_cmd();
	while (*lex)
	{
		if ((type = (*lex)->type) > 32)
		{
			// cmd_suf_push_back(&cmd->cmd_suf, *lex);
		}
		// define для assignment_word в условии ниже
		else if (type > 100500)
		{
			// cmd_pref_push_back(&cmd->cmd_pref, *lex);
		}
		else if (ft_strchr((*lex)->lexeme, '='))
			cmd->cmd_name = (*lex)->lexeme;
		else if (!cmd->cmd_word)
			cmd->cmd_word = (*lex)->lexeme;
		// else
		// 	argument_push_back(cmd, *lex);
		lex = &(*lex)->next;
	}
	return (cmd);
}
