/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_lexer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwisoky <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/29 18:14:21 by dwisoky           #+#    #+#             */
/*   Updated: 2019/08/29 18:21:41 by dwisoky          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "new_lexer.h"

void	print_spec(int type)
{
	if (type == NEWLINE)
		write(1, "\n", 1);
	else if (type == SEMI)
		write(1, ";", 1);
	else if (type == DSEMI)
		write(1, ";;", 2);
	else if (type == AND_IF)
		write(1, "&&", 2);
	else if (type == OR_IF)
		write(1, "||", 2);
	else if (type == PIPE)
		write(1, "|", 1);
}

void	print_lexer(t_lex *lex)
{
	while (lex)
	{
		if (lex->type == WORD)
			ft_putstr((char*)lex->lexem);
		if (lex->type == IO_NUMBER)
			ft_putnbr((int)lex->lexem);
		else
			print_spec(lex->type);
		write(1, " ", 1);
		lex = lex->next;
	}
	write(1, "\n", 1);
}
