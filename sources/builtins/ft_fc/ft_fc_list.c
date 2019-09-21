/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fc_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelisan <gmelisan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 18:39:53 by gmelisan          #+#    #+#             */
/*   Updated: 2019/09/21 20:05:52 by gmelisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fc.h"

int		ft_abs(int n);

/*
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

*/

static t_dlist	*ft_fc_find_arg_number(char *str, int check_start)
{
	t_dlist	*p;
	int		n;
	int		i;

	n = ft_atoi(str);
	n = (n == 0 ? -1 : n);
	p = g_history->item;
	i = 1;
	while (n < 0 ? p->next : p->prev)
		p = (n < 0 ? p->next : p->prev);
	while (n < 0 ? p->prev : p->next)
	{
		if (i == ft_abs(n))
			return (p);
		i++;
		p = (n < 0 ? p->prev : p->next);
	}
	if (check_start)
		return (n < 0 ? NULL : p);
	return (p);
}

static t_dlist	*ft_fc_find_arg_string(char *str)
{
	t_dlist	*p;

	p = g_history->item;
	ft_dlst2end(&p);
	while (p->prev)
	{
		if (ft_strnequ(((t_string *)p->content)->s, str, len))
			return (p);
		p = p->prev;
	}
	return (NULL);
}

t_dlist			*ft_fc_find_arg(char *str)
{
	t_dlist *p;

	if (ft_isdigit(*str || *str == '+' || *str == '-'))
		p = ft_fc_find_arg_number(str, 1);
	else
		p = ft_fc_find_arg_string(str);
	if (!p)
		print_error("history specification out of range", "fc");
	return (p);
}

void			ft_fc_list(const char **argv, t_cmd_opt opt)
{
	t_dlist *p_first;
	t_dlist *p_last;

	if (argv[g_optind] && argv[g_optind + 1])
	{
		p_first = ft_fc_find_arg(argv[g_optind]);
		p_last = ft_fc_find_arg(argv[g_optind]);
	}
	else if (argv[g_optind])
	{
		p_first = ft_fc_find_arg(argv[g_optind]);
		p_last = ft_fc_find_arg_number("-1", 0);
	}
	else
	{
		p_first = ft_fc_find_arg_number("-17", 0);
		p_last = ft_fc_find_arg_number("-1", 0);
	}
	// TODO: build array from first to last and show it
	
	get_first_last(&first, &last);
	list(first, last, opt);
}
