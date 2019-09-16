/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_check_word.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwisoky <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 16:56:37 by dwisoky           #+#    #+#             */
/*   Updated: 2019/09/15 19:18:40 by dwisoky          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

char		*parser_check_word()
{
	char	*str;
	char	*new_str;

	if (g_lex->type != WORD)
		return (NULL);
	new_str = NULL;
	str = g_lex->lexem;
	new_str = parser_word_expansion(str);
	return (new_str);
}
