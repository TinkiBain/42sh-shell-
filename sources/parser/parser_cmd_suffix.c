/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_cmd_suffix.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggwin-go <ggwin-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/05 22:18:22 by ggwin-go          #+#    #+#             */
/*   Updated: 2019/07/28 22:22:30 by ggwin-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "ft_vector.h"

static t_cmd_suffix	*init_cmd_suffix(t_lex *lex)
{
	t_cmd_suffix	*cmd_suf;

	cmd_suf = (t_cmd_suffix*)ft_xmalloc(sizeof(t_cmd_suffix));
	cmd_suf->word = NULL;
	cmd_suf->io_redir = parser_io_redirect(lex);
	cmd_suf->cmd_suf = NULL;
	return (cmd_suf);
}

void				parser_cmd_suffix(t_lex *lex, t_cmd_suffix **cmd_suffix,
										t_cmd *cmd)
{
	while (lex)
	{
		if (lex->type & WORD)
		{
			cmd->cmd_av = vec_addback(cmd->cmd_av,
									(void *)ft_strdup(lex->lexeme));
		}
		else
		{
			*cmd_suffix = init_cmd_suffix(lex);
			cmd_suffix = &(*cmd_suffix)->cmd_suf;
		}
		lex = lex->next;
	}
	char **av = (char **)(cmd->cmd_av->v);
	// ft_putendl(av[0]);
	// ft_putendl(av[1]);
	// ft_putendl(av[2]);
	// while (*av)
	// {
		ft_putstr(*av);
	// 	++av;
	// 	if (*av)
	// 		ft_putchar(' ');
	// }
}
