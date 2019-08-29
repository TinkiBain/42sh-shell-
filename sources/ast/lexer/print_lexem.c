/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_lexem.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwisoky <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/29 20:46:01 by dwisoky           #+#    #+#             */
/*   Updated: 2019/08/29 21:13:07 by dwisoky          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

void	print_spec(int type)
{
	if (type == 1)
		write(1, "\\n", 2);
	else if (type == 2)
		ft_putstr(";");
	else if (type == 3)
		ft_putstr(";;");
	else if (type == 4)
		ft_putstr("&&");
	else if (type == 5)
		ft_putstr("||");
	else if (type == 6)
		ft_putstr("|");
	else if (type == 9)
		ft_putstr("&");
	else if (type == 10)
		ft_putstr("&>");
	else if (type == 11)
		ft_putstr("&>>");
	else if (type == 12)
		ft_putstr("&<");
	else if (type == 13)
		ft_putstr(">|");
	else if (type == 14)
		ft_putstr(">");
	else if (type == 15)
		ft_putstr(">>");
	else if (type == 16)
		ft_putstr(">>&");
	else if (type == 17)
		ft_putstr("<");
	else if (type == 18)
		ft_putstr("<<");
	else if (type == 19)
		ft_putstr("<<");
	else if (type == 20)
		ft_putstr("<<-");
	else if (type == 21)
		ft_putstr("<&");
	else if (type == 22)
		ft_putstr("<>");
	else if (type == 23)
		ft_putstr("!");
	write(1, " " ,1);
}

void	print_lexem(t_lex *lex)
{
	while (lex->back)
		lex = lex->back;
	while (lex)
	{
		if (lex->type == WORD)
		{
			ft_putstr((char*)lex->lexem);
			ft_putstr(" ");
		}
		else
			print_spec(lex->type);
		lex = lex->next;
	}
	write(1, "\n", 1);
}
