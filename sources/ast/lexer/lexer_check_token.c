/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_check_token.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwisoky <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/29 19:26:07 by dwisoky           #+#    #+#             */
/*   Updated: 2019/09/09 21:50:24 by dwisoky          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

char	*lexer_get_great(char *str, t_lex **lex)
{
	++str;
	if (*str == '>')
		init_lex(DGREAT, NULL, lex);
	else if (*str == '|')
		init_lex(CLOBBER, NULL, lex);
	else if (*str == '&')
		init_lex(GREATAND, NULL, lex);
	else
	{
		--str;
		init_lex(GREAT, NULL, lex);
	}
	return (str);
}

char	*lexer_get_less(char *str, t_lex **lex)
{
	++str;
	if (*str == '<')
	{
		if (*(str + 1) == '<' && ++str)
			init_lex(TLESS, NULL, lex);
		else if (*(str + 1) == '&' && ++str)
			init_lex(DLESSAND, NULL, lex);
		else if (*(str + 1) == '-' && ++str)
			init_lex(DLESSDASH, NULL, lex);
		else
			init_lex(DLESS, NULL, lex);
	}
	else if (*str == '>')
		init_lex(LESSGREAT, NULL, lex);
	else if (*str == '&')
		init_lex(LESSAND, NULL, lex);
	else
	{
		--str;
		init_lex(LESS, NULL, lex);
	}
	return (str);
}

char	*lexer_get_and(char *str, t_lex **lex)
{
	++str;
	if (*str == '&')
		init_lex(AND_IF, NULL, lex);
	else if (*str == '<')
		init_lex(ANDLESS, NULL, lex);
	else if (*str == '>' && *(str + 1) == '>')
	{
		++str;
		init_lex(ANDDGREAT, NULL, lex);
	}
	else if (*str == '>')
		init_lex(ANDGREAT, NULL, lex);
	else
	{
		--str;
		init_lex(JOB, NULL, lex);
	}
	return (str);
}

char	*lexer_check_token(char *str, t_lex **lex)
{
	if (*str == '>')
		str = lexer_get_great(str, lex);
	else if (*str == '<')
		str = lexer_get_less(str, lex);
	else if (*str == '&')
		str = lexer_get_and(str, lex);
	else if (*str == ';' && *(str + 1) != ';')
		init_lex(SEMI, NULL, lex);
	else if (*str == ';')
	{
		init_lex(DSEMI, NULL, lex);
		++str;
	}
	else if (*str == '|' && *(str + 1) != '|')
		init_lex(PIPE, NULL, lex);
	else if (*str == '|')
	{
		++str;
		init_lex(OR_IF, NULL, lex);
	}
	return (str);
}
