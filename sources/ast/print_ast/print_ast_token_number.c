/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ast_token_number.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggwin-go <ggwin-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/18 22:50:45 by ggwin-go          #+#    #+#             */
/*   Updated: 2019/08/18 23:03:27 by ggwin-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "print_ast.h"

static int	check_redir_less(int type)
{
	int		res;

	res = 0;
	if (type & LESS && (res = 1))
		ft_putstr("<");
	else if (type & DLESS && (res = 1))
		ft_putstr("<<");
	else if (type & TLESS && (res = 1))
		ft_putstr("<<<");
	else if (type & DLESSDASH && (res = 1))
		ft_putstr("<<-");
	else if (type & LESS && (res = 1))
		ft_putstr("<");
	else if (type & LESSAND && (res = 1))
		ft_putstr("<&");
	else if (type & LESSGREAT && (res = 1))
		ft_putstr("<>");
	return (res);
}

void		print_ast_token_number(int type)
{
	if (type & SEMICOLON)
		ft_putstr(";");
	else if (type & PIPE_SYMB)
		ft_putstr("|");
	else if (type & AND_IF)
		ft_putstr("&&");
	else if (type & OR_IF)
		ft_putstr("||");
	else if (type & GREAT)
		ft_putstr(">");
	else if (type & DGREAT)
		ft_putstr(">>");
	else if (type & GREATAND)
		ft_putstr(">&");
	else if (type & ANDGREAT)
		ft_putstr("&>");
	else if (type & ANDDGREAT)
		ft_putstr("&>>");
	else if (type & CLOBBER)
		ft_putstr(">|");
	else
		check_redir_less(type);
}
