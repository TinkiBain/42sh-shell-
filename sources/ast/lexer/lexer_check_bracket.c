/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_check_bracket.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwisoky <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 17:31:43 by dwisoky           #+#    #+#             */
/*   Updated: 2019/09/19 18:11:58 by dwisoky          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

char	*lexer_check_bracket(char *str, t_lex **lex)
{
	if (*str == '(')
		init_lex(LBRACKET, NULL, lex);
	else if (*str == ')')
		init_lex(RBRACKET, NULL, lex);
	else if (*str == '#')
	{
		str = ft_strchr(str, '\n');
		if (!str)
			return ("a");
	}
	return (str);
}
