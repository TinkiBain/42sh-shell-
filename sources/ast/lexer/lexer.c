/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwisoky <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/29 19:15:46 by dwisoky           #+#    #+#             */
/*   Updated: 2019/09/06 17:14:51 by dwisoky          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"
#include "sh.h"

void		init_lex(int type, void *lexem, t_lex **lex)
{
	t_lex	*tmp;

	if (*lex)
		tmp = (*lex)->next;
	else
		tmp = *lex;
	tmp = (t_lex*)xmalloc(sizeof(t_lex));
	if (*lex)
		(*lex)->next = tmp;
	tmp->type = type;
	tmp->lexem = lexem;
	tmp->back = *lex;
	tmp->next = NULL;
	*lex = tmp;
}

int			lexer_check_spec_symbol(char c)
{
	if (c == ';' || c == '|' || c == '<' || c == '>' || c == '&' || c == '(' ||
			c == ')')
		return (1);
	return (0);
}

int			lexer_isspace(char c)
{
	if (c == ' ' || c == '\t' || c == '\r' || c == '\f' || c == '\v')
		return (1);
	return (0);
}

t_lex		*lexer(char *str)
{
	t_lex	*lex;

	lex = NULL;
	while (*str)
	{
		if (lexer_isspace(*str) && ++str)
			continue ;
		if (*str == '\n')
			init_lex(NEWLINE, NULL, &lex);
		if (*str == '(')
			init_lex(WORD, ft_strdup("("), &lex);
		else if (*str == ')')
			init_lex(WORD, ft_strdup(")"), &lex);
		else if (*str == '>' || *str == '<' || *str == '|' || *str == '&'
				|| *str == ';')
			str = lexer_check_token(str, &lex);
		else if (*str >= '0' && *str <= '9')
			str = lexer_check_io_number(str, &lex);
		else
			str = lexer_find_word(str, &lex);
		++str;
	}
	init_lex(NEWLINE, NULL, &lex);
	return (lex);
}
