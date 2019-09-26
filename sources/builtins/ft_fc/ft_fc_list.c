/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fc_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelisan <gmelisan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 18:39:53 by gmelisan          #+#    #+#             */
/*   Updated: 2019/09/26 22:03:15 by gmelisan         ###   ########.fr       */
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

void			ft_fc_list_get_first_last(const char **argv, t_dlist **pp_first,
											t_dlist **pp_last, int *asc)
{
	if (!pp_first || !pp_last)
		return ;
	if (argv[g_optind] && argv[g_optind + 1])
	{
		*pp_first = ft_fc_find_arg(argv[g_optind]);
		*pp_last = ft_fc_find_arg(argv[g_optind + 1]);
	}
	else if (argv[g_optind])
	{
		*pp_first = ft_fc_find_arg(argv[g_optind]);
		*pp_last = ft_fc_find_arg_number("-2", 0);
	}
	else
	{
		*pp_first = ft_fc_find_arg_number("-17", 0);
		*pp_last = ft_fc_find_arg_number("-2", 0);
	}
	*asc = ft_fc_is_asc(*pp_first, *pp_last);
}

t_vector		ft_fc_build_vector(const char **argv, int *start)
{
	t_vector	vec;
	t_dlist		*p_first;
	t_dlist		*p_last;
	int			asc;

	vec = vec_create(0, sizeof(t_string));
	ft_fc_list_get_first_last(argv, &p_first, &p_last, &asc);
	*start = get_start(p_first);
	*start = (asc ? *start : *start * -1);
	if (!p_first || !p_last)
		return (vec);
	while (p_first && p_first != p_last)
	{
		vec_addback(&vec, p_first->content);
		p_first = (asc ? p_first->next : p_first->prev);
	}
	if (p_first == p_last)
		vec_addback(&vec, p_first->content);
	return (vec);
}

void			ft_fc_list(const char **argv, t_cmd_opt opt)
{
	t_vector	vec;
	int			i;
	t_string	*s;
	int			start;

	vec = ft_fc_build_vector(argv, &start);
	i = 0;
	while ((s = vec_get(vec, i))) /* TODO: indices not shifted by start_index :( */
	{
		if (opt.n)
			ft_printf("\t%s\n", s->s);
		else
			ft_printf("%d\t%s\n", ft_abs(start), s->s);
		i++;
		start++;
	}
	ft_memdel(&vec.v);
}
