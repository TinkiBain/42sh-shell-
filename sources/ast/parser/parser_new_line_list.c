/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_new_line_list.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggwin-go <ggwin-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 20:30:55 by dwisoky           #+#    #+#             */
/*   Updated: 2019/09/16 18:02:17 by dwisoky          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

/*
** Grammar rule
**	newline_list     :              NEWLINE
**	                 | newline_list NEWLINE
**	                 ;
*/

char				*parser_call_back_readline()
{
	extern int		g_eof;
	extern t_opt 	g_opt;
	char			*tmp;
	extern char		*g_buf;

	tmp = ft_readline((g_opt.rl_gnl == 0 ?
				get_var_value("PS3") : ""), RL_APPEND);
	ft_putstr(g_opt.rl_gnl == 0 ? "\n" : "");
	free(g_buf);
	g_buf = tmp;
	if (g_eof)
	{
		init_lex(EOF, NULL, &g_lex);
		g_eof = 0;
		return (NULL);
	}
	return (tmp);
}

void				parser_new_line_list(void)
{
	char			*buf;
	t_lex			*tmp;

	while (g_lex && g_lex->type == NEWLINE)
	{
		tmp = g_lex;
		g_lex = g_lex->next;
		if (!g_end_parsing)
		{
			buf = parser_call_back_readline();
			if (!buf)
				break ;
			g_lex = lexer(buf);
			while (g_lex->back)
				g_lex = g_lex->back;
			tmp->next = g_lex;
		}
	}
}
