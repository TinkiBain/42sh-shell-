/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_and_or.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggwin-go <ggwin-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/29 18:34:38 by dwisoky           #+#    #+#             */
/*   Updated: 2019/07/09 19:23:47 by dwisoky          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

size_t			lexer_and_or(char *str, t_lex **lex)
{
	if (*str == '&' && *(str + 1) && *(str + 1) == '&')
		(*lex)->type = AND_IF;
	else if (*str == '|' && *(str + 1) && *(str + 1) == '|')
		(*lex)->type = OR_IF;
	else
		return (0);
	return (2);
}
