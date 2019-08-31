/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_check_reserved_word.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwisoky <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/29 19:54:00 by dwisoky           #+#    #+#             */
/*   Updated: 2019/08/29 20:59:13 by dwisoky          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

int			lexer_check_reserved_word_do(char *str, t_lex **lex)
{
	if (ft_strequ(str, "do"))
		init_lex(DO, str, lex);
	else if (ft_strequ(str, "done"))
		init_lex(DONE, str, lex);
	else if (ft_strequ(str, "in"))
		init_lex(IN, str, lex);
	else if (ft_strequ(str, "{"))
		init_lex(LBRACE, str, lex);
	else if (ft_strequ(str, "}"))
		init_lex(RBRACE, str, lex);
	else
		return (0);
	return (1);
}

int			lexer_check_reserved_word(char *str, t_lex **lex)
{
	if (ft_strequ(str, "if"))
		init_lex(IF, str, lex);
	else if (ft_strequ(str, "for"))
		init_lex(FOR, str, lex);
	else if (ft_strequ(str, "!"))
		init_lex(BANG, str, lex);
	else if (ft_strequ(str, "case"))
		init_lex(CASE, str, lex);
	else if (ft_strequ(str, "esac"))
		init_lex(ESAC, str, lex);
	else if (ft_strequ(str, "while"))
		init_lex(WHILE, str, lex);
	else if (ft_strequ(str, "until"))
		init_lex(UNTIL, str, lex);
	else if (ft_strequ(str, "then"))
		init_lex(THEN, str, lex);
	else if (ft_strequ(str, "else"))
		init_lex(ELSE, str, lex);
	else if (ft_strequ(str, "elif"))
		init_lex(ELIF, str, lex);
	else if (lexer_check_reserved_word_do(str, lex))
		return (1);
	else
		return (0);
	return (1);
}
