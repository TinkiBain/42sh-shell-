/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arithmetic_lexer_digit.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwisoky <dwisoky@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/23 17:38:49 by dwisoky           #+#    #+#             */
/*   Updated: 2019/10/30 19:21:08 by dwisoky          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arithmetic.h"

char	*arithmetic_lexer_digit(char *str, t_lex **lex)
{
	char	*begin;

	begin = str;
	if (*str == '0' && *(str + 1) == 'x')
	{
		str += 2;
		while (ft_isdigit(*str) || (*str >= 'A' && *str <= 'F') ||
				(*str >= 'a' && *str <= 'f'))
			++str;
	}
	else
		while (ft_isdigit(*str))
			++str;
	begin = ft_xstrndup(begin, str - begin);
	init_lex(DIGIT, begin, lex);
	return (str);
}
