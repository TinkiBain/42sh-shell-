/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_new_line_list.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwisoky <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 20:30:55 by dwisoky           #+#    #+#             */
/*   Updated: 2019/09/09 19:05:43 by dwisoky          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

/*
 ** Grammar rule
 **	newline_list     :              NEWLINE
 **	                 | newline_list NEWLINE
 **	                 ;
*/

void				parser_new_line_list(void)
{
	char			*buf;
	t_lex			*tmp;
	extern t_opt 	g_opt;
	extern int		g_exit;

	while (g_lex && g_lex->type == NEWLINE)
	{
		tmp = g_lex;
		g_lex = g_lex->next;
		if (!g_end_parsing)
		{
			buf = ft_readline((g_opt.rl_in == 0 ?
										get_var_value("PS2") : ""), NULL);
			ft_putstr(g_opt.rl_in == 0 ? "\n" : "");
			if (g_exit)
			{
				init_lex(EOF, NULL, &g_lex);
				g_exit = 0;
				return ;
			}
			g_lex = lexer(buf);
			while (g_lex->back)
				g_lex = g_lex->back;
			tmp->next = g_lex;
			free(buf);
		}
	}
}
