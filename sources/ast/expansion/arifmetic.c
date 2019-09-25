/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arifmetic_exp.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwisoky <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/22 16:40:09 by dwisoky           #+#    #+#             */
/*   Updated: 2019/09/25 22:19:09 by dwisoky          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arifmetic.h"

size_t		expr_digit(void)
{
	size_t	value;

	value = atoll(g_lex_arif->lexem);
	g_lex_arif = g_lex_arif->next;
	return (value);
}

char		*arifmetic_exp(char *str)
{
	size_t	rez;
	t_lex	*lex;

	str += 3;
	rez = 0;
	str[ft_strlen(str) - 2] = '\0';
	lex = arifmetic_lexer(str);
	g_error_arifmetic = NULL;
	g_lex_arif = lex;
	if (lex)
		rez = expr();
	if (g_error_arifmetic)
		printf("%d\n", g_error_arifmetic->type);
	lexer_free_all(lex);
	return (ft_itoa_base(rez, 10));
}
