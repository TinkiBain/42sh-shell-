/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fc_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelisan <gmelisan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 18:39:53 by gmelisan          #+#    #+#             */
/*   Updated: 2019/09/16 14:42:10 by gmelisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fc.h"

static void	list(int first, int last, t_cmd_opt opt)
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
		{
			if (opt.n)
				ft_printf("\t%s\n", ((t_string *)p->content)->s);
			else
				ft_printf("%d\t%s\n", i, ((t_string *)p->content)->s);
		}
		i++;
		p = p->next;
	}
}

void		get_first_last(int *first, int *last)
{
	*first = g_history->start_index + g_history->size - 17;
	*last = g_history->start_index + g_history->size - 1;
}

void		ft_fc_list(t_cmd_opt opt)
{
	int		first;
	int		last;

	get_first_last(&first, &last);
	list(first, last, opt);
}
