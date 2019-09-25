/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arifmetic_lexer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwisoky <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/23 17:21:28 by dwisoky           #+#    #+#             */
/*   Updated: 2019/09/24 15:50:50 by dwisoky          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arifmetic.h"

char		*arifmetic_lexer_bracket(char *str, t_lex **lex)
{
	if (*str == '(')
		init_lex(RBRACKET_ARIF, NULL, lex);
	else
		init_lex(LBRACKET_ARIF, NULL, lex);
	++str;
	return (str);
}

t_lex		*arifmetic_lexer(char *str)
{
	t_lex	*lex;

	lex = NULL;
	while (*str)
	{
		if (ft_isspace(*str))
		{
			++str;
			continue ;
		}
		if (ft_isalpha(*str))
			str = arifmetic_lexer_var(str, &lex);
		else if (ft_isdigit(*str))
			str = arifmetic_lexer_digit(str, &lex);
		else if (*str == '(' || *str == ')')
			str = arifmetic_lexer_bracket(str, &lex);
//		else if (*str == '!' && ++str)
//			init_lex(LOGICAL_NOT, NULL, &lex);
//		else if (*str == '?' && ++str)
//			init_lex(TERN_
		else
			str = arifmetic_lexer_check_token(str, &lex);
	}
	if (!lex)
		return (NULL);
	while (lex->back)
		lex = lex->back;
	return (lex);
}
