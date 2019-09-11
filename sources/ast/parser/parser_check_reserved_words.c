/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_check_reserved_words.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwisoky <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 18:23:12 by dwisoky           #+#    #+#             */
/*   Updated: 2019/09/11 22:11:07 by dwisoky          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int		parser_check_reserved_words(void)
{
	if (g_lex->type != WORD)
		return (0);
	if (ft_strequ(g_lex->lexem, "!"))
		return (1);
	else if (ft_strequ(g_lex->lexem, "{"))
		return (1);
	else if (ft_strequ(g_lex->lexem, "}"))
		return (1);
	else if (ft_strequ(g_lex->lexem, "case"))
		return (1);
	else if (ft_strequ(g_lex->lexem, "do"))
		return (1);
	else if (ft_strequ(g_lex->lexem, "done"))
		return (1);
	else if (ft_strequ(g_lex->lexem, "elif"))
		return (1);
	else if (ft_strequ(g_lex->lexem, "else"))
		return (1);
	else if (ft_strequ(g_lex->lexem, "esac"))
		return (1);
	else if (ft_strequ(g_lex->lexem, "fi"))
		return (1);
	else if (ft_strequ(g_lex->lexem, "for"))
		return (1);
	else if (ft_strequ(g_lex->lexem, "if"))
		return (1);
	else if (ft_strequ(g_lex->lexem, "in"))
		return (1);
	else if (ft_strequ(g_lex->lexem, "then"))
		return (1);
	else if (ft_strequ(g_lex->lexem, "until"))
		return (1);
	else if (ft_strequ(g_lex->lexem, "while"))
		return (1);
	return (0);
}
