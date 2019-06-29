/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwisoky <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/26 17:25:18 by dwisoky           #+#    #+#             */
/*   Updated: 2019/06/29 19:46:11 by dwisoky          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

t_lex		*init_lex(void)
{
	t_lex	*lex;

	lex = (t_lex*)ft_xmalloc(sizeof(t_lex));
	lex->lexeme = NULL;
	lex->type = 0;
	lex->next = NULL;
	lex->fd = 0;
	return (lex);
}

void		lexer(char *buf)
{
	t_lex	*lex;
	t_lex	*begin;

	lex = init_lex();
	begin = lex;
	while (*buf)
	{
		if (ft_isspace(*buf))
		{
			++buf;
			continue ;
		}
		if (*buf == '|' && ((*(buf + 1) && *(buf + 1) != '|') || !*(buf + 1)))
			lex->type = PIPE;
		else if (*buf == ';')
			lex->type = SEMICOLON;
		else
			buf = lexer_get_token(buf, &lex);
		lex->next = init_lex();
		lex = lex->next;
	}
	free(lex);
	lex = NULL;
}

/* TO DO */

int			main(void)
{
	char	buf[1024];

	while (1)
	{
		buf[read(0, &buf, 1023) - 1] = '\0';
		if (ft_strequ("exit", buf))
			break ;
		lexer(buf);
	}
	return (0);
}
