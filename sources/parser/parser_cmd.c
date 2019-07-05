/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_cmd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggwin-go <ggwin-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/04 20:47:34 by ggwin-go          #+#    #+#             */
/*   Updated: 2019/07/05 22:24:11 by ggwin-go         ###   ########.fr       */
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

t_cmd	*parser_cmd(t_lex *lex)
{
	t_cmd		*cmd;
	int			type;

	if (!lex)
		return (NULL);
	cmd = init_cmd();
	if ((type = lex->type) & LESS || type & DLESS || type & DLESSDASH
		|| type & TLESS || type & LESSAND || type & LESSGREAT)
	{
		cmd->cmd_pref = parser_cmd_prefix(lex);
	}
	else if (type & LESSGREAT || type & GREAT || type & DGREAT
		|| type & GREATAND || type & ANDGREAT || type & ANDDGREAT)
	{
		cmd->cmd_suf = parser_cmd_suffix(lex);
	}
	else if (ft_strchr(lex->lexeme, '='))
		cmd->cmd_name = lex->lexeme;
	else if (!cmd->cmd_word)
		cmd->cmd_word = lex->lexeme;
	return (cmd);
}
