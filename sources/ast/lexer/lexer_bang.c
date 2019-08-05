/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_bang.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwisoky <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/02 19:13:10 by dwisoky           #+#    #+#             */
/*   Updated: 2019/08/02 19:30:37 by dwisoky          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

char	*lexer_bang(char *str, t_lex *lex)
{
	if (!lex->prev || (lex->prev->type == AND_IF || lex->prev->type == OR_IF
				|| lex->prev->type == PIPE_SYMB))
		lex->type = BANG;
	else
	{
		lex->lexeme = ft_strdup("!");
		lex->type = WORD;
	}
	return (str + 1);
}
