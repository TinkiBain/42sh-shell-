/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_free_all.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwisoky <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/25 18:57:23 by dwisoky           #+#    #+#             */
/*   Updated: 2019/08/25 18:57:24 by dwisoky          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

static void	free_lex(t_lex *lex)
{
	if (!lex)
		return ;
	if (lex->lexeme)
		free(lex->lexeme);
	free(lex);
}

void		lexer_free_all(t_lex *lex)
{
	t_lex	*tmp;

	if (!lex)
		return ;
	while (lex->prev)
	{
		tmp = lex;
		lex = lex->prev;
		free_lex(tmp);
	}
	free_lex(lex);
}
