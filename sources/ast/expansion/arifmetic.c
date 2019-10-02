/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arifmetic_exp.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwisoky <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/22 16:40:09 by dwisoky           #+#    #+#             */
/*   Updated: 2019/10/02 22:11:04 by dwisoky          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arifmetic.h"

void			arifmetic_error(char *str, t_lex *begin)
{
	ft_putstr_fd(g_project_name, 2);
	ft_putstr_fd(": ", 2);
	ft_putstr_fd(str, 2);
	if (g_error_arifmetic->type == DIVISION_NULL)
		ft_putstr_fd(": division by 0 ", 2);
	else if (g_error_arifmetic->type >= 3 && g_error_arifmetic->type <= 12)
		ft_putstr_fd(": attempted assignment to non-variable ", 2); 
	else
		ft_putstr_fd(": syntax error: operand expected ", 2);
	ft_putstr_fd("(error token is \"", 2);
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

size_t			expr_atoll(char *str, int base)
{
	size_t		rez;

	if (!str)
		return (0);
	rez = 0;
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
	return (rez);
}

size_t			expr_digit(void)
{
	size_t	value;

	if (*(g_lex_arif->lexem + 1) == 'x')
		value = expr_atoll(g_lex_arif->lexem, 16);
	else
		value = expr_atoll(g_lex_arif->lexem, 10);
	g_lex_arif = g_lex_arif->next;
	return (value);
}

char			*arifmetic_exp(char *str)
{
	size_t	rez;
	t_lex	*lex;

	str += 3;
	rez = 0;
	str[ft_strlen(str) - 2] = '\0';
	str = ft_strtrim(str);
	lex = arifmetic_lexer(str);
	g_error_arifmetic = NULL;
	g_lex_arif = lex;
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
