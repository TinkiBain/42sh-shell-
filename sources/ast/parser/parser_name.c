/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_name.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwisoky <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 21:17:02 by dwisoky           #+#    #+#             */
/*   Updated: 2019/09/13 22:22:28 by dwisoky          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

/*
** Grammar rule
** name             : NAME                      Apply rule 5
**                  ;
*/

char		*parser_name(void)
{
	char *str;

	str = g_lex->lexem;
	if (*str >= '0' && *str <= '9')
	{
		g_error_lex = g_lex;
		return (NULL);
	}
	while (*str)
	{
		if ((*str >= '0' && *str <= '9') || (*str == '_') || (*str >= 'a' &&
					*str <= 'z') || (*str >= 'A' && *str <= 'Z'))
			++str;
		else
		{
			g_error_lex = g_lex;
			return (NULL);
		}
	}
	return (ft_strdup(g_lex->lexem));
}
