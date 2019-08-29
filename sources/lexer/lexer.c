/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwisoky <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/29 17:19:54 by dwisoky           #+#    #+#             */
/*   Updated: 2019/08/29 18:51:32 by dwisoky          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "new_lexer.h"

void		init_lex(int type, void *lexem, t_lex **lex)
{
	t_lex	*tmp;

	if (!*lex)
		tmp = *lex;
	else
		tmp = (*lex)->next;
	tmp = (t_lex*)xmalloc(sizeof(t_lex));
	tmp->type = type;
	tmp->lexeme = lexeme;
	tmp->back = *lex;
	tmp->next = NULL;
	*lex = tmp;
}

t_lex		*new_lexer(char *str)
{
	t_lex	*lex;

	lex = NULL;
	while (*str)
	{
		if (ft_isspase(*str) && ++str)
			continue ;
		if (*str == '\n')
			init_lex(NEWLINE, NULL, &lex);
		else if (*str == ';' || *str == '|' || *str == '&' || *str == '>'
				|| *str == '<')
			str = lexer_check_token(str, &lex);
	//	else if (*str >= '0' && *str <= '9')
	//		str = lexer_check_nb(str, &lex);
		else
			str = lexer_check_reserved_word(str, &lex);
		++str;
	}
	return (lex);
}
