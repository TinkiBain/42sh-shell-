/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arifmetic.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwisoky <dwisoky@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/22 16:40:09 by dwisoky           #+#    #+#             */
/*   Updated: 2019/10/11 19:36:33 by dwisoky          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arifmetic.h"

void			arifmetic_error(char *str, t_lex *begin)
{
	if (g_error_arifmetic->type == DIVISION_NULL)
		print_error_vaarg("%s: division by 0 ", str);
	else if (g_error_arifmetic->type >= 3 && g_error_arifmetic->type <= 12)
		print_error_vaarg("%s: attempted assignment to non-variable ", str);
	else
		print_error_vaarg("%s: syntax error: operand expected", str);
	ft_putstr_fd("(error token is \"", STDERR);
	if (!g_lex_arif)
	{
		while (begin->next)
			begin = begin->next;
		ft_putstr_fd(begin->lexem, 2);
	}
	while (g_lex_arif)
	{
		ft_putstr_fd(g_lex_arif->lexem, 2);
		if (g_lex_arif->next)
			ft_putstr_fd(" ", 2);
		g_lex_arif = g_lex_arif->next;
	}
	ft_putendl_fd("\")", 2);
}

char			*arifmetic_print_lex_error(char *str)
{
	print_error_vaarg("%s: syntax error: operand expected "
			"(error token is \"%s\")\n", str, g_error_arifmetic->lexem);
	lexer_free_all(g_error_arifmetic);
	lexer_free_all(g_lex_arif);
	return (NULL);
}

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

char			*arifmetic_exp(char *str)
{
	long	rez;
	t_lex	*lex;

	str += 3;
	rez = 0;
	str[ft_strlen(str) - 2] = '\0';
	str = ft_strtrim(str);
	g_error_arifmetic = NULL;
	lex = arifmetic_lexer(str);
	g_lex_arif = lex;
	if (g_error_arifmetic)
		return (arifmetic_print_lex_error(str));
	if (lex)
		rez = expr();
	if (g_lex_arif && !g_error_arifmetic)
		g_error_arifmetic = g_lex_arif;
	if (g_error_arifmetic)
		arifmetic_error(str, lex);
	lexer_free_all(lex);
	free(str);
	return (ft_itoa_base(rez, 10));
}
