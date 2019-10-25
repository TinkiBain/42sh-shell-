/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arithmetic.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwisoky <dwisoky@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/22 16:40:09 by dwisoky           #+#    #+#             */
/*   Updated: 2019/10/12 19:22:14 by dwisoky          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arithmetic.h"

int				expr_sign(char **str)
{
	int			flag;

	flag = 0;
	while (**str == '-' || **str == '+')
	{
		if (**str == '-')
			flag++;
		(*str)++;
	}
	return (flag);
}

long			expr_atoll(char *str, int base)
{
	long		rez;
	int			flag;

	if (!str)
		return (0);
	rez = 0;
	flag = expr_sign(&str);
	if (base == 16)
	{
		if (*str == '0' || *(str + 1))
			str += 2;
		else
			return (0);
	}
	while (*str)
	{
		if (base == 16 && *str >= 'A' && *str <= 'F')
			rez = rez * 16 + (*str - 50);
		else if (base == 16 && (*str >= 'a' && *str <= 'f'))
			rez = rez * 16 + (*str - 82);
		else
			rez = rez * base + (*str - '0');
		++str;
	}
	return (flag % 2 ? rez * -1 : rez);
}

long			expr_digit(void)
{
	long	value;

	if (*(g_lex_arif->lexem + 1) == 'x')
		value = expr_atoll(g_lex_arif->lexem, 16);
	else
		value = expr_atoll(g_lex_arif->lexem, 10);
	g_lex_arif = g_lex_arif->next;
	return (value);
}

char			*arithmetic_exp(char *str)
{
	char	*tmp;
	long	rez;
	t_lex	*lex;

	tmp = str;
	str += 3;
	rez = 0;
	str[ft_strlen(str) - 2] = '\0';
	str = ft_strtrim(str);
	free(tmp);
	g_error_arithmetic = NULL;
	lex = arithmetic_lexer(str);
	g_lex_arif = lex;
	if (g_error_arithmetic)
		return (arithmetic_print_lex_error(str));
	if (lex)
		rez = expr();
	if (g_lex_arif && !g_error_arithmetic)
		g_error_arithmetic = g_lex_arif;
	if (g_error_arithmetic)
		return (arithmetic_error(str, lex));
	lexer_free_all(lex);
	free(str);
	return (ft_itoa_base(rez, 10));
}
