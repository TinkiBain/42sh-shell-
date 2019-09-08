/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fc.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelisan <gmelisan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/22 16:26:34 by gmelisan          #+#    #+#             */
/*   Updated: 2019/09/08 06:55:31 by gmelisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

static void	list(int first, int last)
{
	t_dlist	*p;
	int		i;

	p = g_history->item;
	while (p->prev)
		p = p->prev;
	i = g_history->start_index;
	while (p->next)
	{
		if (i >= first && i <= last)
			ft_printf("%d\t%s\n", i, ((t_string *)p->content)->s);
		i++;
		p = p->next;
	}
}

void		get_first_last(const char **av, int *first, int *last)
{
	if (!av)
		return ;
	*first = g_history->start_index + g_history->size - 17;
	*last = g_history->start_index + g_history->size - 1;
}

int			ft_fc(const char **av)
{
	int first;
	int last;

	if (ft_strequ(av[0], "-l"))
	{
		get_first_last(av, &first, &last);
		list(first, last);
	}
	return (0);
}
