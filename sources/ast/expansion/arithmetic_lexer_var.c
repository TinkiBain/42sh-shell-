/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arithmetic_lexer_var.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwisoky <dwisoky@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/23 17:35:08 by dwisoky           #+#    #+#             */
/*   Updated: 2019/10/15 17:24:54 by dwisoky          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arithmetic.h"

char		*arithmetic_lexer_check_suffix(char *str, t_lex **lex, char c)
{
	if (*(str + 1) == c)
	{
		str += 2;
		if (c == '+')
			init_lex(SUFFIX_ADD, ft_xstrdup("++"), lex);
		else
			init_lex(SUFFIX_MIN, ft_xstrdup("--"), lex);
	}
	return (str);
}

char		*arithmetic_lexer_var(char *str, t_lex **lex)
{
	char	*begin;

	begin = str;
	while (ft_isalpha(*str) || ft_isdigit(*str))
		++str;
	begin = ft_xstrndup(begin, str - begin);
	init_lex(VAR, begin, lex);
	if (*str == '+' || *str == '-')
		str = arithmetic_lexer_check_suffix(str, lex, *str);
	return (str);
}
