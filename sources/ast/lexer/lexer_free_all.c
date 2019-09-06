/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_free_all.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwisoky <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 18:22:00 by dwisoky           #+#    #+#             */
/*   Updated: 2019/09/06 18:22:02 by dwisoky          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

void		lexer_free_all(t_lex *lex)
{
	t_lex	*tmp;

	while (lex)
	{
		tmp = lex->next;
		if (lex->lexem)
			free(lex->lexem);
		free(lex);
		lex = tmp;
	}
}
