/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fc_find_arg.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelisan <gmelisan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/26 20:34:34 by gmelisan          #+#    #+#             */
/*   Updated: 2019/09/27 18:48:10 by gmelisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fc.h"

t_dlist			*ft_fc_find_arg_number(const char *str)
{
	t_dlist	*p;
	int		n;
	int		i;

	n = ft_atoi(str);
	n = (n == 0 ? -1 : n);
	p = g_history->item;
	i = (n > 0 ? g_history->start_index : 0);
	while (n < 0 ? p->next : p->prev)
		p = (n < 0 ? p->next : p->prev);
	while (n < 0 ? p->prev : p->next)
	{
		if (i == ft_abs(n))
			return (p);
		i++;
		p = (n < 0 ? p->prev : p->next);
	}
	if (n > 0 && n < g_history->start_index)
		return (NULL);
	return (p);
}

static t_dlist	*ft_fc_find_arg_string(const char *str)
{
	t_dlist	*p;
	size_t	len;

	p = g_history->item;
	ft_dlst2end(&p);
	len = ft_strlen(str);
	while (p->prev)
	{
		if (ft_strnequ(((t_string *)p->content)->s, str, len))
			return (p);
		p = p->prev;
	}
	return (NULL);
}

t_dlist			*ft_fc_find_arg(const char *str)
{
	t_dlist *p;

	if (ft_isdigit(*str) || *str == '+' || *str == '-')
		p = ft_fc_find_arg_number(str);
	else
		p = ft_fc_find_arg_string(str);
	return (p);
}
