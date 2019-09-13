/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_new_line_list.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggwin-go <ggwin-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 20:30:55 by dwisoky           #+#    #+#             */
/*   Updated: 2019/09/13 19:29:06 by dwisoky          ###   ########.fr       */
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
	extern t_opt 	g_opt;
	char			*tmp;
	extern char		*g_buf;
	int				len;

	tmp = ft_readline((g_opt.rl_in == 0 ?
				get_var_value("PS3") : ""), g_buf);
	ft_putstr(g_opt.rl_in == 0 ? "\n" : "");
	len = ft_strlen(g_buf);
	free(g_buf);
	g_buf = tmp;
	return (tmp + len);
}

void				parser_new_line_list(void)
{
	char			*buf;
	t_lex			*tmp;
	extern int		g_exit;

	while (g_lex && g_lex->type == NEWLINE)
	{
		tmp = g_lex;
		g_lex = g_lex->next;
		if (!g_end_parsing)
		{
			buf = parser_call_back_readline();
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
		}
	}
}
