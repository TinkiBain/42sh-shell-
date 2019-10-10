/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_io_number.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggwin-go <ggwin-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 20:13:28 by dwisoky           #+#    #+#             */
/*   Updated: 2019/10/09 21:48:55 by dwisoky          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int		parser_io_number(void)
{
	int	tmp;
	int	nb;
	int	i;

	nb = 0;
	i = 0;
	while (g_lex->lexem[i] >= '0' && g_lex->lexem[i] <= '9')
	{
		tmp = nb * 10 + (g_lex->lexem[i] - '0');
		if (tmp < nb)
		{
			nb = -2;
			break ;
		}
		nb = tmp;
		++i;
	}
	g_lex = g_lex->next;
	return (nb);
}
