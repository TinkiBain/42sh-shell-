/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_check_token.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwisoky <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/29 18:22:30 by dwisoky           #+#    #+#             */
/*   Updated: 2019/08/29 18:48:19 by dwisoky          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "new_lexer.h"

char	*lexer_check_great(char *str)
{
	++str;
	if (*str == '>')
		init_lex(DGREAT, NULL, lex);
	else if (*str == '&')
		init_lex(GREATAND, NULL, lex);
	else if (*str == '|')
		init_lex(CLOBBER, NULL, lex);
	else
	{
		--str;
		init_lex(GREAT, NULL, lex);
	}
	return (str);
}

char	*lexer_check_less(char *str, t_lex **lex)
{
	++str;
	if (*str == '<')
	{
		++str;
		if (*str == '<')
			init_lex(TLESS, NULL, lex);
		else if (*str == '-')
			init_lex(DLESSDASH, NULL, lex);
		else
		{
			init_lex(DLESS);
			--str;
		}
	}
	else if (*str == '&')
		init_lex(LESSAND, NULL, lex);
	else if (*str == '>')
		init_lex(LESSGREAT, NULL, lex);
	else
	{
		init_lex(LESS, NULL, lex);
		--str;
	}
	return (str);
}

char	*lexer_check_and(char *str, t_lex **lex)
{
	++str;
	if (*str == '>')
		init_lex(ANDGREAT, NULL, lex);
	else if (*str == '<')
		init_lex(ANDLESS, NULL, lex);
	else if (*str == '&')
		init_lex(AND_IF, NULL, lex);
	else
	{
		init_lex(JOBS, NULL, lex);
		--str;
	}
	return (str);
}

char	*lexer_check_token(char *str, t_lex **lex)
{
	if (*str == '>')
		str = lexer_check_great(str, lex);
	else if (*str == '<')
		str = lexer_check_less(str, lex);
	else if (*str == '&')
		str = lexer_check_and(str, lex);
	else if (*str == '|' && *(str + 1) != '|')
		init_lex(PIPE, NULL, lex);
	else if (*str == '|')
	{
		init_lex(OR_IF, NULL, lex);
		++str;
	}
	else if (*str == ';' && *(str + 1) != ';')
		init_lex(SEMI, NULL, lex);
	else if (*str == ';')
	{
		++str;
		init_lex(DSEMI, NULL, lex);
	}
	return (str);
}
