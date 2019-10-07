/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fc_build_vector.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelisan <gmelisan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 18:04:12 by gmelisan          #+#    #+#             */
/*   Updated: 2019/10/07 19:34:58 by gmelisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fc.h"

static int		ft_fc_is_asc(t_dlist *p_first, t_dlist *p_last)
{
	t_dlist		*p;

	p = p_first;
	while (p->next)
	{
		if (p == p_last)
			return (1);
		p = p->next;
	}
	return (0);
}

static int		get_start(t_dlist *p_first)
{
	t_dlist *p;
	int		i;

	p = g_history->item;
	ft_dlst2start(&p);
	i = g_history->start_index;
	while (p != p_first)
	{
		i++;
		p = p->next;
	}
	return (i);
}

t_vector		ft_fc_build_vector(const char **argv, int *start, t_cmd_opt opt,
			void (*get_first_last)(const char **, t_dlist **, t_dlist **))
{
	t_vector	vec;
	t_dlist		*p_first;
	t_dlist		*p_last;
	int			asc;

	vec = vec_create(0, sizeof(t_string));
	get_first_last(argv, &p_first, &p_last);
	if (!p_first || !p_last)
		return (vec);
	asc = ft_fc_is_asc(p_first, p_last);
	*start = get_start(opt.r ? p_last : p_first);
	*start = (asc ? *start : *start * -1);
	while (p_first && p_first != p_last)
	{
		vec_addback(&vec, p_first->content);
		p_first = (asc ? p_first->next : p_first->prev);
	}
	if (p_first == p_last)
		vec_addback(&vec, p_first->content);
	return (vec);
}
