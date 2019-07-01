/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_and_or.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwisoky <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/01 09:48:32 by dwisoky           #+#    #+#             */
/*   Updated: 2019/07/01 12:59:15 by dwisoky          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

t_and_or		*parser_and_or(t_lex *lex)
{
	while (lex)
	{
		printf("%s\n", lex->lexeme);
		printf("%d\n", lex->fd);
		printf("%d\n", lex->type);
		printf("--------------\n");
		lex = lex->next;
	}
	printf("	END AND_OR		\n");
	return (NULL);
}
