/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arifmetic_lexer_var.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwisoky <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/23 17:35:08 by dwisoky           #+#    #+#             */
/*   Updated: 2019/10/02 16:46:56 by dwisoky          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arifmetic.h"

char		*arifmetic_lexer_check_suffix(char *str, t_lex **lex, char c)
{
	if (*(str + 1) == c)
	{
		str += 2;
		if (c == '+')
			init_lex(SUFFIX_ADD, ft_strdup("++"), lex);
		else
			init_lex(SUFFIX_MIN, ft_strdup("--"), lex);
	}
	return (str);
}

char		*arifmetic_lexer_var(char *str, t_lex **lex)
{
	char	*begin;

	begin = str;
	while (ft_isalpha(*str) || ft_isdigit(*str))
		++str;
	begin = ft_strndup(begin, str - begin);
	init_lex(VAR, begin, lex);
	if (*str == '+' || *str == '-')
		str = arifmetic_lexer_check_suffix(str, lex, *str);
	return (str);
}
