/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_linebreak.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwisoky <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/15 15:31:45 by dwisoky           #+#    #+#             */
/*   Updated: 2019/08/15 15:32:59 by dwisoky          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

t_lex		*parser_linebreak(t_lex *lex)
{
	while (lex && lex->type & NEWLINE)
		lex = lex->next;
	return (lex);
}
