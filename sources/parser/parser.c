/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwisoky <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/30 19:52:13 by dwisoky           #+#    #+#             */
/*   Updated: 2019/06/30 21:35:20 by dwisoky          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

t_list		*init_list(void)
{
	t_list	*list;

	list = (t_list*)ft_xmalloc(sizeof(t_list));
	list->next = NULL;
	list->and_or = NULL;
	list->sep = 0;
	return (list);
}

void		parser(t_lex *lex)
{
	t_list	*list;

	list = init_list();
	
}
