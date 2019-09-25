/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arifmetic_lexer_digit.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwisoky <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/23 17:38:49 by dwisoky           #+#    #+#             */
/*   Updated: 2019/09/24 15:32:53 by dwisoky          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arifmetic.h"

char	*arifmetic_lexer_digit(char *str, t_lex **lex)
{
	char	*begin;

	begin = str;
	while (ft_isdigit(*str))
		++str;
	begin = ft_strndup(begin, str - begin);
	init_lex(DIGIT, begin, lex);
	return (str);
}
