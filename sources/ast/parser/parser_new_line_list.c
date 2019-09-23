/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_new_line_list.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggwin-go <ggwin-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 20:30:55 by dwisoky           #+#    #+#             */
/*   Updated: 2019/09/23 14:10:46 by ggwin-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

/*
** Grammar rule
**	newline_list     :              NEWLINE
**	                 | newline_list NEWLINE
**	                 ;
*/

char				*parser_call_back_readline(int lex_or)
{
	extern int		g_eof;
	extern t_opt	g_opt;
	char			*tmp;
	extern char		*g_buf;

	tmp = ft_readline((g_opt.rl_gnl == 0 ?
				get_var_value("PS3") : ""), RL_APPEND);
	if (!g_eof)
		ft_putstr(g_opt.rl_gnl == 0 ? "\n" : "");
	free(g_buf);
	g_buf = tmp;
	if (g_eof)
	{
		if (lex_or)
			init_lex(EOF, NULL, &g_lex);
		else
			init_lex(EOF, NULL, &g_error_lex);
		return (NULL);
	}
	return (tmp);
}

void				parser_new_line_list(void)
{
	char			*buf;
	extern int		g_eof;
	t_lex			*tmp;

	while (g_lex && g_lex->type == NEWLINE)
	{
		tmp = g_lex;
		g_lex = g_lex->next;
		if (!g_end_parsing)
		{
			buf = parser_call_back_readline(1);
			if (!buf)
			{
				g_eof = 0;
				break ;
			}
			g_lex = lexer(buf);
			while (g_lex->back)
				g_lex = g_lex->back;
			tmp->next = g_lex;
		}
	}
}
