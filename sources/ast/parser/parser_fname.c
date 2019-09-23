/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_fname.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggwin-go <ggwin-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 22:00:41 by dwisoky           #+#    #+#             */
/*   Updated: 2019/09/23 14:17:10 by ggwin-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

/*
** Grammar rule
** fname            : NAME                            Apply rule 8
**                  ;
*/

char		*parser_fname(void)
{
	char	*str;

	if (parser_check_reserved_words())
	{
		g_error_lex = g_lex;
		return (NULL);
	}
	str = parser_name();
	if (g_error_lex)
		g_lex->type = NOT_VALID_ID;
	return (str);
}
