/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggwin-go <ggwin-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/26 17:25:18 by dwisoky           #+#    #+#             */
/*   Updated: 2019/07/15 18:15:18 by dwisoky          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

t_lex		*init_lex(t_lex *prev)
{
	t_lex	*lex;

	lex = (t_lex*)ft_xmalloc(sizeof(t_lex));
	lex->lexeme = NULL;
	lex->type = 0;
	lex->next = NULL;
	lex->prev = prev;
	lex->fd = 0;
	return (lex);
}

void		check_first_semicolon_token(t_lex **begin)
{
	t_lex	*lex;

	if ((*begin)->type & SEMICOLON)
	{
		lex = *begin;
		lex = lex->next;
		free(lex->prev);
		lex->prev = NULL;
		*begin = lex;
	}
}

static int	lexer_check_separator(char *str)
{
	if (*str == ';')
		return (1);
	if (*str == '&')
		if (*(str + 1) && (*(str + 1) != '&' &&  *(str + 1) != '>'))
			return (1);
	return (0);
}

t_lex		*lexer(char *buf)
{
	t_lex	*lex;

	lex = init_lex(NULL);
	while (*buf)
	{
		if (ft_isspace(*buf) && ++buf)
			continue ;
		if (*buf == '|' && ((*(buf + 1) && *(buf + 1) != '|')
							|| !*(buf + 1)) && ++buf)
			lex->type = PIPE_SYMB;
		else if (lexer_check_separator(buf) && ++buf)
			lex->type = SEMICOLON;
		else
			buf = lexer_get_token(buf, &lex);
		lex->next = init_lex(lex);
		lex = lex->next;
	}
	lex = lex->prev;
	free(lex->next);
	lex->next = NULL;
	while (lex->prev)
		lex = lex->prev;
	check_first_semicolon_token(&lex);
	return (lex);
}

/*
**	while (lex)
**	{
**		printf("%d\n", lex->type);
**		printf("'%s'\n", lex->lexeme);
**		printf("%d\n", lex->fd);
**		printf("-------------------\n");
**		lex = lex->next;
**	}
*/